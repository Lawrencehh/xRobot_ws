
/*该节点负责输送带和摄像头云台的控制命令下发*/
#include <ros/ros.h> 
#include <string>
#include <serial/serial.h>  //ROS已经内置了的串口包 
#include "turtlebot_teleop/twist_hh.h"


serial::Serial ser; //声明串口对象 

void testCallback(const turtlebot_teleop::twist_hh::ConstPtr & msg)
{
        std::string data;
        // 声明字符串数据 data


      unsigned char camera_L[7]={0xff,0x01,0x00,0x04, //
     0x20,0x00,0x25};                                //摄像头左转

      unsigned char camera_R[7]={0xff,0x01,0x00,0x02, //
     0x20,0x00,0x23};                                //摄像头右转

     unsigned char camera_U[7]={0xff,0x01,0x00,0x08, //
     0x00,0x2c,0x35};                                //摄像头上抬

      unsigned char camera_D[7]={0xff,0x01,0x00,0x10, //
     0x00,0x23,0x34};                                //摄像头下降

      unsigned char camera_stop[7]={0xff,0x01,0x00,0x00, //
     0x00,0x00,0x01};                                //摄像头停止

     unsigned char belt_R[8]={0x03,0x06,0x00,0x00, //
     0x1b,0x58,0x83,0x22};                                //输送带旋转

      unsigned char belt_stop[8]={0x03,0x06,0x00,0x00, //
     0x00,0x00,0x88,0x28};                                //输送带停止

        long angle = (long)msg->camera_angle;
        ROS_INFO_STREAM("camera_angle:"<<angle);


        

        if(msg->camera_angle>0){
           ROS_INFO_STREAM("camera_angle:" << angle);
        //在控制台输出传给串口的数据
           ser.write(camera_L,7);
        }

        if(msg->camera_angle<0){
           ROS_INFO_STREAM("camera_angle:" << angle);
        //在控制台输出传给串口的数据
           ser.write(camera_R,7);
        }

        if(msg->camera_tilt>0){

           ser.write(camera_U,7);
        }

        if(msg->camera_tilt<0){

           ser.write(camera_D,7);
        }

        if(msg->belt > 0){

           ser.write(belt_R,8);
        }

        if(msg->belt == 0){

           ser.write(belt_stop,8);
        }
        

        if(msg->camera_angle==0 && msg->camera_tilt==0){

            ROS_INFO_STREAM(msg->camera_angle);
        //在控制台输出传给串口的数据
            ser.write(camera_stop,7);
        }
        
        //向串口输出数据data
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "send_data_serialPort");
    
    ros::NodeHandle nh;

    ros::Subscriber joy_sub_;

//   joy_sub_ = nh.subscribe<turtlebot_teleop::twist_hh>("func_motors", 10, &testCallback, this);
    

    /* code for main function */

    /***************************打开串口 ****************************/
    try 
    { 
    //设置串口属性，并打开串口 
    // ser.setPort("/dev/pts/22");//这是一个虚拟串口，用来发送消息，而/dev/pts/20会接收到通过此串口发送的消息， 具体的串口值需本机检查确认
    // 更改这里的串口号
    // ser.setPort("/dev/ttyUSB0");
    ser.setPort("/dev/ttyUSB1");


    ser.setBaudrate(9600);    
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

    joy_sub_ = nh.subscribe<turtlebot_teleop::twist_hh>("func_motors", 10, testCallback);
    ros::spin();

    // joy_sub_ = nh.subscribe<turtlebot_teleop::twist_hh>("func_motors", 10);
    


    // ros::Rate loop_rate(1);
    // int count(0);

    // while(ros::ok())
    // {
    //     std::string data,camera_L;
    //     // 声明字符串数据 data

    //     camera_L = "Hello world!!";
    //     //这里可任意更改发送给串口的数据信息
    //     //更改任何信息后，需要在工作空间根目录执行catkin_make命令进行编译
       

    //     data = camera_L;


    //     ROS_INFO_STREAM(data);
    //     //在控制台输出传给串口的数据

    //     ser.write(data);
    //     //向串口输出数据data

    //     loop_rate.sleep();
    // }



    return 0;
}
