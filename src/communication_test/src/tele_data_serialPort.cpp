
/*该节点负责采集电台串口传送过来的远程控制箱的控制信息，并发布给底盘速度话题和功能电机话题*/

#include <ros/ros.h> 
#include <string>
#include <serial/serial.h>  //ROS已经内置了的串口包 
#include <math.h> 
#include "sensor_msgs/NavSatFix.h"
#include "turtlebot_teleop/twist_hh.h"  //引用自定义消息类型
#include <geometry_msgs/Twist.h>

#include <std_msgs/String.h>
#include <std_msgs/Empty.h> 
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdlib>//string转化为double
#include <iomanip>//保留有效小数





serial::Serial ser; //声明串口对象 

//将串口数据转为twist数据和cmd_vel数据
void CopeSerialData(std::string str_in)
{
    unsigned int str_length = str_in.size();
    static unsigned char chrTemp[2000];
    static unsigned char ucRxCnt = 0;
    static unsigned int usRxLength = 0;

    memcpy(chrTemp,str_in.data(),str_length);
    usRxLength += str_length;
    while (usRxLength >= 11)
    {
        if (chrTemp[0] != 0x55)
        {
            usRxLength--;
            memcpy(&chrTemp[0],&chrTemp[1],usRxLength);
            continue;
        }
        switch(chrTemp[1])
        {
            case 0x50:	memcpy(&stcTime,&chrTemp[2],8);break;
            case 0x51:	memcpy(&stcAcc,&chrTemp[2],8);break;
            case 0x52:	memcpy(&stcGyro,&chrTemp[2],8);break;
            case 0x53:	memcpy(&stcAngle,&chrTemp[2],8);break;
            case 0x54:	memcpy(&stcMag,&chrTemp[2],8);break;
            case 0x55:	memcpy(&stcDStatus,&chrTemp[2],8);break;
            case 0x56:	memcpy(&stcPress,&chrTemp[2],8);break;
            case 0x57:	memcpy(&stcLonLat,&chrTemp[2],8);break;
            case 0x58:	memcpy(&stcGPSV,&chrTemp[2],8);break;
        }
        usRxLength -= 11;
        memcpy(&chrTemp[0],&chrTemp[11],usRxLength);
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "tele_data_serialPort");
    
    ros::NodeHandle nh;

    // ros::Subscriber gps_sub_;
    ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1, true); //所有电机的状态发布
    ros::Publisher func_motor_pub = nh.advertise<turtlebot_teleop::twist_hh>("func_motors",1,true); //所有电机的状态发布

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

    ros::Rate loop_rate(50);

    std::string strRece;
    while (ros::ok())
    {

        if (ser.available())
        {
            //1.读取串口信息：
            ROS_INFO_STREAM("Reading from serial port\n");

            //将串口数据转为twist_hh数据和cmd_vel数据
            CopeSerialData(serial_port.read(serial_port.available()));

            //



            


        }
    ros::spinOnce();
    loop_rate.sleep();
    }
    return 0;
}
