
/*该节点负责采集GPS信号及其他相关信息（包括车轮速度，机械臂角度，），并传送数据给电台*/

#include <ros/ros.h> 
#include <string>
#include <serial/serial.h>  //ROS已经内置了的串口包 
#include <math.h> 

#include "sensor_msgs/NavSatFix.h"
#include "turtlebot_teleop/twist_hh.h"  //引用自定义消息类型
#include "communication_test/func_motors_feedback.h"  //引用自定义消息类型
#include <geometry_msgs/Twist.h>

#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>




serial::Serial ser; //声明串口对象 

class multiRobotData
{
public:
	multiRobotData()
	{	
		// sub = nh.subscribe("xqserial_server/func_motors_feedback", 1, &multiRobotData::arm_autoCallback,this);
		// sub2 = nh.subscribe("joy", 1, &multiRobotData::joyCallback,this);

        gps_sub_ = nh.subscribe<sensor_msgs::NavSatFix>("fix", 1, &multiRobotData::gpsCallback,this);
        twist_sub_ = nh.subscribe<geometry_msgs::Twist>("cmd_vel", 1, &multiRobotData::twistCallback,this);
        func_motors_sub_ = nh.subscribe<communication_test::func_motors_feedback>("func_motors_feedback", 1, &multiRobotData::func_motorsCallback,this);
        twist_hh_sub_ = nh.subscribe<turtlebot_teleop::twist_hh>("func_motors", 1, &multiRobotData::twist_hhCallback,this);
    }
    void twistCallback(const geometry_msgs::Twist::ConstPtr & msg);
    void twist_hhCallback(const turtlebot_teleop::twist_hh::ConstPtr & msg);
    void func_motorsCallback(const communication_test::func_motors_feedback::ConstPtr & msg);
    void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr & msg);
 
private:
    ros::NodeHandle nh;
    ros::Subscriber gps_sub_;
    ros::Subscriber twist_sub_;
    ros::Subscriber func_motors_sub_;
    ros::Subscriber twist_hh_sub_;
  
};

void multiRobotData::twistCallback(const geometry_msgs::Twist::ConstPtr & msg){

   
    int vel = (int)floor(100*msg->linear.x);
    ROS_INFO_STREAM("vel="<<vel);
    ROS_INFO_STREAM("vel="<<(unsigned char)(vel+100));

    unsigned char data[4] = {};
    data[0]=(char)0x8F; //帧头
    data[1]=(char)0x02; //功能码，代表传输底盘速度信息
    data[3]=(char)0xF8;//帧尾
    data[2]=(unsigned char)(vel+100);//将速度值转为16进制0x00~0xC8(200)
    ser.write(data,4);
}

void multiRobotData::twist_hhCallback(const turtlebot_teleop::twist_hh::ConstPtr & msg){
    
    int belt = (int)msg->belt;
    int oblique_drawer = (int)msg->oblique_drawer;
    int flat_drawer = (int)msg->flat_drawer;
    ROS_INFO_STREAM("oblique_drawer="<<oblique_drawer);
    ROS_INFO_STREAM("flat_drawer="<<flat_drawer);
    ROS_INFO_STREAM("belt="<<belt);


    unsigned char data[6] = {};
    data[0]=(char)0x8F; //帧头
    data[1]=(char)0x03; //功能码，代表传输输送带、斜板抽屉和伸缩柜信息
    data[5]=(char)0xF8;//帧尾

    data[2]=(unsigned char)(belt);//将输送带值转为16进制0x00~0x01
    data[3]=(unsigned char)(oblique_drawer+1);//将斜板抽屉转为16进制0x00~0x02，0x01表示静止，0x00表示闭合，0x02表示展开
    data[4]=(unsigned char)(flat_drawer+1);//将伸缩柜转为16进制0x00~0x02，0x01表示静止，0x00表示闭合，0x02表示展开

    ser.write(data,6);
    

}

void multiRobotData::func_motorsCallback(const communication_test::func_motors_feedback::ConstPtr & msg){
    int Encorder_linearModule = (int)floor(msg->Encorder_linearModule/6150); //数字为0~100，0的时候为初始位置，100的时候为最大位置
    int Hall_putter_1 = (int)floor(msg->Hall_putter_1_left/80);//数字为0~100，0的时候为初始位置，100的时候为最大位置
    int Hall_putter_2 = (int)floor(msg->Hall_putter_2_left/6360);//数字为0~100，0的时候为初始位置，100的时候为最大位置
    int Hall_putter_3 = (int)floor(msg->Hall_putter_3_left/1050);//数字为0~100，0的时候为初始位置，100的时候为最大位置

    unsigned char data[7] = {};
    data[0]=(char)0x8F; //帧头
    data[1]=(char)0x02; //功能码，代表传输底盘速度信息
    data[6]=(char)0xF8;//帧尾

    data[2]=(unsigned char)(Encorder_linearModule);//直线模组位置
    data[3]=(unsigned char)(Hall_putter_1);//大臂电动推杆位置
    data[4]=(unsigned char)(Hall_putter_2);//小臂电动推杆位置
    data[5]=(unsigned char)(Hall_putter_3);//斜板电动推杆位置

    ser.write(data,7);
}

void multiRobotData::gpsCallback(const sensor_msgs::NavSatFix::ConstPtr & msg)
{
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


        unsigned char data[11] = {};
        data[0]=(char)0x8F; //帧头
        data[1]=(char)0x01; //功能码，代表传输GPS信息
        data[10]=(char)0xF8;//帧尾
        for (int i = 0; i < 4; i++)
        {
            data[i] = lat16[i];
        }

        for (int i = 0; i < 4; i++)
        {
            data[i+4] = long16[i];
        }


           ser.write(data,11);

}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "robot_data_serialPort");
    


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

    multiRobotData test_hh;
    ros::spin();

    return 0;
}
