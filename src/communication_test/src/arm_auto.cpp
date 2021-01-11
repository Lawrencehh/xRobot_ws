#include <ros/ros.h> 
#include <string>
#include "communication_test/func_motors_feedback.h"
#include <sensor_msgs/Joy.h>

#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include "turtlebot_teleop/twist_hh.h"  //引用自定义消息类型

int auto_flag = 0; //自动轨迹规划运行flag，为1时执行第一段，为2时执行第二段，为0时退出自动轨迹规划

int epoch = 0;       //轨迹规划阶段值，初始值为0


//每个阶段的目标值
int goal_Encorder_linearModule[] = \   
{0,0,0,0,605000,325000,315000,215000,65000,30000,0,0,0};               //总行程615000脉冲×××××     直线模组

int goal_Hall_putter_1_left[] = \       
{0,0,0,0,8100,8100,6450,4900,2900,500,0,0,0};                     //总行程8000脉冲×××××××     大臂

int goal_Hall_putter_2_left[] = \       
{480000,240000,240000,0,0,0,200000,340000,380000,550000,636000,240000,480000};               //总行程636000脉冲×××××     小臂

int goal_Hall_putter_3_left[] = \       
{0,0,100000,100000,100000,100000,100000,102000,102000,102000,102000,102000,0};          //总行程105000脉冲××××××    斜板
   

/******************************可以debug**************************************/
int epoch_init_1 = 1; //第一段起始步数
int epoch_init_2 = 4; //第二段起始步数
#define epoch_division 4            //定义分割步数，前epoch_division步数运行第一段，后面运行第二段
#define epoch_length 13              //定义总步数，需要与goal的数组长度一致

double ratio =1;
const double ratio_config=0.5;
/******************************可以debug**************************************/


//误差阈值参数error，需要在现场调参数
const double error_Encorder_linearModule = 1000; //1mm 1000个脉冲   ###直线模组
const double error_putter_1 = 100;  //1mm 100个脉冲                 ###大臂
const double error_putter_2 = 2000; //1mm 2000个脉冲                ###小臂
const double error_putter_3 = 1000; //1mm 1000个脉冲                ###斜板

//P参数，需要在现场调参数, 这里设定为当运行到误差容忍区间时刻的速度百分比
const double p_Encorder_linearModule = 30/error_Encorder_linearModule;
const double p_putter_1 = 60/error_putter_1;
const double p_putter_2 = 30/error_putter_2;
const double p_putter_3 = 15/error_putter_3; 
//斜板

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

        if(epoch_switch == 6) {
            ratio = ratio_config;
        }



        else ratio =1;
        ROS_INFO_STREAM("epoch_switch:>>>"<<epoch_switch);
        ROS_INFO_STREAM("ratio:>>>"<<ratio);
        //直线模组
        func_motors.linear_module = p_Encorder_linearModule*(goal_Encorder_linearModule[epoch_switch] - msg->Encorder_linearModule); //线性模组的前进后退
        if(func_motors.linear_module > 100) func_motors.linear_module = 100;
        if(func_motors.linear_module < -100) func_motors.linear_module = -100;
        func_motors.linear_module=ratio*func_motors.linear_module;

        
        //大臂
        func_motors.putter_1 = -p_putter_1*(goal_Hall_putter_1_left[epoch_switch] - msg->Hall_putter_1_left); //大臂
        if(func_motors.putter_1 > 100) func_motors.putter_1 = 100;
        if(func_motors.putter_1 < -100) func_motors.putter_1 = -100;
        func_motors.putter_1 = ratio*func_motors.putter_1;
        
        //小臂
        func_motors.putter_2 = -p_putter_2*(goal_Hall_putter_2_left[epoch_switch] - msg->Hall_putter_2_left); 
        if(func_motors.putter_2 > 100)  func_motors.putter_2 = 100;
        if(func_motors.putter_2 < -100) func_motors.putter_2 = -100;
        if(epoch_switch == 3) {
            func_motors.putter_2 = 0.5*func_motors.putter_2;
        }
       
        //斜板角度推杆控制
        func_motors.oblique_angle = p_putter_3*(goal_Hall_putter_3_left[epoch_switch] - msg->Hall_putter_3_left);
        if(func_motors.oblique_angle > 100)  func_motors.oblique_angle = 100;
        if(func_motors.oblique_angle < -100) func_motors.oblique_angle = -100;
        if(abs(goal_Hall_putter_3_left[epoch_switch] - msg->Hall_putter_3_left)<error_putter_3)
        func_motors.oblique_angle = 0;
       
        if(epoch_switch>=3)
        func_motors.oblique_drawer = 1; //斜板抽屉推杆控制

        if(epoch_switch>=3)
        func_motors.flat_drawer = 1; //伸缩柜伸展控制 ×××××××××××××××××××在加装限位开关后可以改为1
        else func_motors.flat_drawer = 0;

        if(epoch_switch>=4 && epoch_switch <=8)        func_motors.belt = 1; //输送带动作控制
        else                        func_motors.belt = 0;
        
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


    if(auto_flag > 0){

        //当flag为1时候执行第一段自动代码
        if(auto_flag == 1){
            switch (epoch)
            {
            default:
                this->auto_switch(epoch,msg);
                break;

            
            case epoch_division:
                ROS_INFO_STREAM("EPOCH 1 ALL DONE！！");
                this->motors_stop();
                break;
        
            }
        }

            
            //当flag为2时候执行第二段自动代码
        if(auto_flag == 2){
            switch (epoch)
            {
            default:
                this->auto_switch(epoch,msg);
                break;            
            
            case epoch_length:
                ROS_INFO_STREAM("EPOCH 2 ALL DONE！！");
                this->motors_stop();
            break;            
            }
        }    
    }   
}
 
void multiReceiver::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
    
    if(joy->buttons[6]==1 && joy->buttons[1]==1 && joy->buttons[5]==1)
    auto_flag = 1,epoch = epoch_init_1;  

    else if(joy->buttons[6]==1 && joy->buttons[1]==1 && joy->buttons[7]==1)
    auto_flag = 2,epoch = epoch_init_2;

    else auto_flag = 0, epoch = 0;      //断开自动轨迹规划模式时，将epoch置为0;
    ROS_INFO_STREAM("auto_flag:"<<auto_flag);
}
  
 
int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "arm_auto");
 
  

  multiReceiver test_hh;
  ros::spin();
 
  return 0;
}
