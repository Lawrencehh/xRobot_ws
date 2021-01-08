#include <ros/ros.h> 
#include <string>
#include "communication_test/func_motors_feedback.h"
#include <sensor_msgs/Joy.h>

#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>

using namespace sensor_msgs;
using namespace message_filters;

bool auto_flag = false; //自动轨迹规划运行flag，为true时执行，为false时退出自动轨迹规划
int epoch = 0;       //轨迹规划阶段值，初始值为0



//反馈信号回调函数
//手柄驱动回调函数
void arm_autoCallback(const sensor_msgs::Joy::ConstPtr& joy,const communication_test::func_motors_feedback::ConstPtr & msg)
{
    

    if(joy->buttons[6]==1 && joy->buttons[11]==1)
    auto_flag = true;
    else auto_flag = false;
    ROS_INFO_STREAM("auto_flag:"<<auto_flag);

    



}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "arm_auto");
    
    ros::NodeHandle nh;
    
    // ros::Subscriber joy_sub_;
    // ros::Subscriber feedback_sub_;
    // joy_sub_ = nh.subscribe<sensor_msgs::Joy>(nh,"joy", 1);
    // feedback_sub_ = nh.subscribe<communication_test::func_motors_feedback>(nh,"func_motors", 1);

    message_filters::Subscriber<sensor_msgs::Joy> joy_sub_(nh, "joy", 1);
    message_filters::Subscriber<communication_test::func_motors_feedback> feedback_sub_(nh, "func_motors", 1);



    // TimeSynchronizer<sensor_msgs::Joy, communication_test::func_motors_feedback> sync(joy_sub_, feedback_sub_, 10);

    // sync.registerCallback(boost::bind(&arm_autoCallback, _1, _2));

    
    ros::spin();



    return 0;
}