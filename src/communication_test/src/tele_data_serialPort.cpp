
/*该节点负责采集电台串口传送过来的远程控制箱的控制信息，并发布给底盘速度话题和功能电机话题*/

#include <ros/ros.h> 
#include <string>
#include <serial/serial.h>  //ROS已经内置了的串口包 
#include <math.h> 
#include "sensor_msgs/NavSatFix.h"


serial::Serial ser; //声明串口对象 

void testCallback(const sensor_msgs::NavSatFix::ConstPtr & msg)
{
       
           ser.write(data,8);

}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "tele_data_serialPort");
    
    ros::NodeHandle nh;

    ros::Subscriber gps_sub_;

    /* code for main function */

    /***************************打开串口 ****************************/
    try 
    { 
    //设置串口属性，并打开串口 
    // 更改这里的串口号
    // ser.setPort("/dev/ttyUSB0");
    ser.setPort("/dev/ttyUSB1");


    ser.setBaudrate(115200);    
    // 更改这里的波特率

    serial::Timeout to = serial::Timeout::simpleTimeout(1000); 
    ser.setTimeout(to); 
    ser.open(); 
    } 
    catch (serial::IOException& e) 
    { 
    ROS_ERROR_STREAM("Unable to open port "); 
    return -1; 
    } 
    //检测串口是否已经打开，并给出提示信息 
    if(ser.isOpen())
    { 
    ROS_INFO_STREAM("Serial Port initialized"); 
    } 
    else 
    { 
    return -1; 
    }    
    /***************************************************************/

    gps_sub_ = nh.subscribe<sensor_msgs::NavSatFix>("fix", 10, testCallback);
    ros::spin();

    return 0;
}
