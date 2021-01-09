#include <ros/ros.h> 
#include <string>
#include "communication_test/func_motors_feedback.h"
#include <sensor_msgs/Joy.h>

#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include "turtlebot_teleop/twist_hh.h"  //引用自定义消息类型

bool auto_flag = false; //自动轨迹规划运行flag，为true时执行，为false时退出自动轨迹规划

int epoch = 0;       //轨迹规划阶段值，初始值为0

//每个阶段的目标值
int goal_Encorder_linearModule[] = {2000,6000};
int goal_Hall_putter_1_left[] = {3000,8000};
int goal_Hall_putter_2_left[] = {1000,2000};
int goal_Hall_putter_3_left[] = {5000,1500};
#define epoch_length 2              //定义总步数，需要与goal的数组长度一致

//P参数，需要在现场调参数
const double p_Encorder_linearModule = 0.2;
const double p_putter_1 = 0.2;
const double p_putter_2 = 0.2;
const double p_putter_3 = 0.2;

//误差阈值参数error，需要在现场调参数
const double error_Encorder_linearModule = 20;
const double error_putter_1 = 20;
const double error_putter_2 = 20;
const double error_putter_3 = 20;

//最小启动速度，需要在现场调参数，当速度值小于该值时候，速度值为零
const double lowest_Encorder_linearModule = p_Encorder_linearModule*error_Encorder_linearModule;
const double lowest_putter_1 = p_putter_1*error_putter_1;
const double lowest_putter_2 = p_putter_2*error_putter_2;
const double lowest_putter_3 = p_putter_3*error_putter_3;


class multiReceiver
{
public:
	multiReceiver()
	{	
		sub = nh.subscribe("xqserial_server/func_motors_feedback", 1, &multiReceiver::arm_autoCallback,this);
		sub2 = nh.subscribe("joy", 1, &multiReceiver::joyCallback,this);
        func_motors_pub_ = nh.advertise<turtlebot_teleop::twist_hh>("func_motors",1,true); //所有电机的控制状态发布
	}
	void arm_autoCallback(const communication_test::func_motors_feedback::ConstPtr & msg);
	void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
    void auto_switch(int &epoch_switch,const communication_test::func_motors_feedback::ConstPtr & msg);
    void motors_stop();
 
private:
	ros::NodeHandle nh;
	ros::Subscriber sub;
	ros::Subscriber sub2;
    turtlebot_teleop::twist_hh func_motors; //功能电机状态
    ros::Publisher func_motors_pub_;  //所有功能电机状态发布
  
};
 
 //复用代码,包含epoch转换和pid中的p控制
 void multiReceiver::auto_switch(int &epoch_switch,const communication_test::func_motors_feedback::ConstPtr & msg)
    {

        ROS_INFO_STREAM("OUTPUT>>>"<<epoch_switch);
        //第一阶段判断是否完成
        if(abs(msg->Encorder_linearModule - goal_Encorder_linearModule[epoch_switch]) <error_Encorder_linearModule && \
        abs(msg->Hall_putter_1_left - goal_Hall_putter_1_left[epoch_switch]) <error_putter_1 && \
        abs(msg->Hall_putter_2_left - goal_Hall_putter_2_left[epoch_switch]) <error_putter_2 && \
        abs(msg->Hall_putter_3_left - goal_Hall_putter_3_left[epoch_switch]) <error_putter_3  \
        ) epoch_switch++;

        //给各个电机赋值
        //直线模组
        func_motors.linear_module = p_Encorder_linearModule*(goal_Encorder_linearModule[epoch_switch] - msg->Encorder_linearModule); //线性模组的前进后退
        if(func_motors.linear_module > 100) func_motors.linear_module = 100;
        if(func_motors.linear_module < -100) func_motors.linear_module = -100;
        if(func_motors.linear_module > -lowest_Encorder_linearModule && func_motors.linear_module < lowest_Encorder_linearModule) func_motors.linear_module = 0;
        //大臂
        func_motors.putter_1 = p_putter_1*(goal_Hall_putter_1_left[epoch_switch] - msg->Hall_putter_1_left); //大臂
        if(func_motors.putter_1 > 100) func_motors.putter_1 = 100;
        if(func_motors.putter_1 < -100) func_motors.putter_1 = -100;
        if(func_motors.putter_1 > -lowest_putter_1 && func_motors.putter_1 < lowest_putter_1) func_motors.putter_1 = 0;
        
        //小臂
        func_motors.putter_2 = p_putter_2*(goal_Hall_putter_2_left[epoch_switch] - msg->Hall_putter_2_left); 
        if(func_motors.putter_2 > 100)  func_motors.putter_2 = 100;
        if(func_motors.putter_2 < -100) func_motors.putter_2 = -100;
        if(func_motors.putter_2 > -lowest_putter_2 &&  func_motors.putter_2 < lowest_putter_2) func_motors.putter_2 = 0;

        //斜板角度推杆控制
        func_motors.oblique_angle = p_putter_3*(goal_Hall_putter_3_left[epoch_switch] - msg->Hall_putter_3_left);
        if(func_motors.oblique_angle > 100)  func_motors.oblique_angle = 100;
        if(func_motors.oblique_angle < -100) func_motors.oblique_angle = -100;
        if(func_motors.oblique_angle > -lowest_putter_3 &&  func_motors.oblique_angle < lowest_putter_3) func_motors.oblique_angle = 0;


        func_motors.oblique_drawer = 1; //斜板抽屉推杆控制
        func_motors.flat_drawer = 0; //伸缩柜伸展控制 ×××××××××××××××××××在加装限位开关后可以改为1

        func_motors.belt = 1; //输送带动作控制
        func_motors.camera_angle = 0;  //摄像头的旋转
        func_motors.camera_tilt = 0; //摄像头俯仰角控制
        func_motors.arm_auto =1; //自动轨迹的使能
        func_motors_pub_.publish(func_motors);    //发布功能电机控制话题                
    }

void multiReceiver::motors_stop()
{
    func_motors.linear_module = 0;
    func_motors.putter_1 = 0;
    func_motors.putter_2 = 0;
    func_motors.oblique_angle = 0;
    func_motors.oblique_drawer = 0;
    func_motors.flat_drawer = 0;
    func_motors.belt = 0;
    func_motors.camera_angle = 0;
    func_motors.camera_tilt = 0;
    func_motors.arm_auto = 1;
    func_motors_pub_.publish(func_motors);    //发布功能电机控制话题

}
 
void multiReceiver::arm_autoCallback(const communication_test::func_motors_feedback::ConstPtr & msg)
{


    if(auto_flag){

            switch (epoch)
            {
            default:
                this->auto_switch(epoch,msg);
                break;
            
            case epoch_length:
                ROS_INFO_STREAM("ALL DONE");
                this->motors_stop();
                break;
            }
        
        }
    
}
 
void multiReceiver::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
    if(joy->buttons[6]==1 && joy->buttons[11]==1)
    auto_flag = true;
    else auto_flag = false, epoch = 0;      //断开自动轨迹规划模式时，将epoch置为0;
    ROS_INFO_STREAM("auto_flag:"<<auto_flag);
}
  
 
int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "arm_auto");
 
  

  multiReceiver test_hh;
  ros::spin();
 
  return 0;
}
