
/*该节点负责采集GPS信号及其他相关信息（包括车轮速度，机械臂角度，），并传送数据给电台*/

#include <ros/ros.h> 
#include <string>
#include <serial/serial.h>  //ROS已经内置了的串口包 
#include <math.h> 
#include "sensor_msgs/NavSatFix.h"


serial::Serial ser; //声明串口对象 

void testCallback(const sensor_msgs::NavSatFix::ConstPtr & msg)
{
        // std::string data;
        // // 声明字符串数据 data


        unsigned char camera_L[7]={0xff,0x01,0x00,0x04, //
        0x20,0x00,0x25};                                //摄像头左转

        ROS_INFO_STREAM("msg->latitude:"<<floor(msg->latitude));
        ROS_INFO_STREAM("msg->latitude:"<<1000000*(msg->latitude-floor(msg->latitude)));
        int lat_integer=floor(msg->latitude);//整数部分
        long lat_decimal=1000000*(msg->latitude-floor(msg->latitude)); //6位小数

        ROS_INFO_STREAM("msg->longitude:"<<floor(msg->longitude));
        ROS_INFO_STREAM("msg->longitude:"<<1000000*(msg->longitude-floor(msg->longitude)));
        int long_integer=floor(msg->longitude);//整数部分
        long long_decimal=1000000*(msg->longitude-floor(msg->longitude)); //6位小数
        
        //将十进制转为十六进制
        unsigned char lat16[4] = {0x00,0x00,0x00,0x00};//16进制表示的北纬度数，第一位为整数位，后三位为小数位

        lat16[0] = lat16[0] + (char)lat_integer;
        lat16[1] = lat16[1] + (char)floor(lat_decimal/65536);
        lat16[2] = lat16[2] + (char)floor(lat_decimal/256);
        lat16[3] = lat16[3] + (char)(lat_decimal%256);

        unsigned char long16[4] = {0x00,0x00,0x00,0x00};//16进制表示的东经度数，第一位为整数位，后三位为小数位
        long16[0] = long16[0] + (char)long_integer;
        long16[1] = long16[1] + (char)floor(long_decimal/65536);
        long16[2] = long16[2] + (char)floor(long_decimal/256);
        long16[3] = long16[3] + (char)(long_decimal%256);


        unsigned char data[8] = {};
        for (int i = 0; i < 4; i++)
        {
            data[i] = lat16[i];
        }

        for (int i = 0; i < 4; i++)
        {
            data[i+4] = long16[i];
        }


           ser.write(data,8);

}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "robot_data_serialPort");
    
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
