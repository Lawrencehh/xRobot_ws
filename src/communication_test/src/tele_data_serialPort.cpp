
/*该节点负责采集电台串口传送过来的远程控制箱的控制信息，并发布给底盘速度话题和功能电机话题*/

#include <ros/ros.h> 
#include <string>
#include <serial/serial.h>  //ROS已经内置了的串口包 
#include <math.h> 
// #include "sensor_msgs/NavSatFix.h"
// #include "turtlebot_teleop/twist_hh.h"  //引用自定义消息类型
// #include "geometry_msgs/Twist.h"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32.h"
// #include <vector>



double Axies[6] = {0.0,0.0,0.0,0.0,0.0,0.0};//罗技手柄摇杆 （-32767，32767）
int buttons[12] = {0,0,0,0,0,0,0,0,0,0,0,0};  //罗技手柄按键
sensor_msgs::Joy Joy_serialPort;




serial::Serial ser; //声明串口对象 

//将串口数据转为twist数据和cmd_vel数据
void CopeSerialData(std::string str_in)
{
    unsigned int str_length = str_in.size();
    static unsigned char chrTemp[2000];
    static unsigned int usRxLength = 0;

    memcpy(chrTemp,str_in.data(),str_length);
    usRxLength += str_length;

    Joy_serialPort.axes.clear();
    Joy_serialPort.buttons.clear();


    while (usRxLength >= 9)
    {
       
        if (chrTemp[0] != 0x7F )    //帧头
        {
            usRxLength--;
            memcpy(&chrTemp[0],&chrTemp[1],usRxLength);
            continue;
        }
        switch(chrTemp[2])//0x0D为手柄协议，0x0C为按键协议，0x09为旋钮
        {
            std::cout << std::hex << (chrTemp[2] & 0xff) << " ";
            case 0x0D:	{
                if(chrTemp[4]==0x01){   //将左侧摇杆赋值给Axies[0]
                    Axies[0]=(float)-1/480*(256.0*(int)chrTemp[5]+(int)chrTemp[6]-512);
                    Axies[1]=(float)1/480*(256.0*(int)chrTemp[7]+(int)chrTemp[8]-512);
                }
                if(chrTemp[4]==0x02){   //将右侧摇杆赋值给Axies[1]
                    Axies[2]=(float)-1/480*(256.0*(int)chrTemp[7]+(int)chrTemp[8]-512);
                    Axies[3]=(float)1/480*(256.0*(int)chrTemp[5]+(int)chrTemp[6]-512);
                }
                usRxLength -= 10;
            //   ROS_INFO_STREAM("usRxLength:"<<usRxLength);
                break;
            }
            case 0x0C:{
                if(chrTemp[8] == 0x3D){
                    buttons[5] = 1-(int)chrTemp[9];    //左侧摇杆按钮，控制摄像头向上
                }
                if(chrTemp[8] != 0x3D){
                    buttons[10] = 1-(int)chrTemp[7];    //急停按钮，底盘使能
                    buttons[6] = 1-(int)chrTemp[7];     //急停按钮，功能电机使能

                    buttons[7] = 1-(int)chrTemp[10];    //左侧摇杆按钮，控制摄像头向上

                    buttons[4] = 1-(int)chrTemp[6];     //控制启动指令按钮，输送带使能

                    buttons[1] = 1-(int)chrTemp[8];     //机械臂自动轨迹规划按钮，自动轨迹规划使能

                }
                usRxLength -= 12;
            }

            case 0x09:{
                Axies[5] = (float)((int)chrTemp[6]-7.5)/7.5;    //第1个旋钮作为直线模组的前进后退
                Axies[4] = (float)-1.0*((int)chrTemp[3]-7.5)/7.5;   //第4个旋钮作为摄像头旋转

                //第2个旋钮，作为斜板角度
                if((int)chrTemp[5]>10){
                    buttons[3] = 1;
                    buttons[11] = 0;
                }
                if((int)chrTemp[5]<5){
                    buttons[3] = 0;
                    buttons[11] = 1;
                }
                if((int)chrTemp[5]<=10 && (int)chrTemp[5]>=5){
                    buttons[3] = 0;
                    buttons[11] = 0;
                }

                //第3个旋钮，作为斜板角度
                if((int)chrTemp[4]>10){
                    buttons[9] = 1;
                    buttons[8] = 0;
                    buttons[2] = 1;
                    buttons[0] = 0;
                }
                if((int)chrTemp[4]<5){
                    buttons[9] = 0;
                    buttons[8] = 1;
                    buttons[2] = 0;
                    buttons[0] = 1;
                }
                if((int)chrTemp[4]<=10 && (int)chrTemp[5]>=5){
                    buttons[9] = 0;
                    buttons[8] = 0;
                    buttons[2] = 0;
                    buttons[0] = 0;
                }
                usRxLength -= 9;
            }

            // case 0x51:	memcpy(&stcAcc,&chrTemp[2],8);break;
            // case 0x52:	memcpy(&stcGyro,&chrTemp[2],8);break;

        }
 
        // memcpy(&chrTemp[0],&chrTemp[11],usRxLength); //将已经处理完的数据推出队列
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "tele_data_serialPort");
    
    ros::NodeHandle nh;

    sensor_msgs::Joy Joy_last;

    // ros::Subscriber gps_sub_;
    ros::Publisher Joy_pub = nh.advertise<sensor_msgs::Joy>("joy", 1, true); //所有电机的状态发布
  

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
         

    while (ros::ok())
    {

        if (ser.available())
        {
            //1.读取串口信息：
            ROS_INFO_STREAM("Reading from serial port\n");

            //将串口数据转为Joy数据
            CopeSerialData(ser.read(ser.available()));

            for (int i = 0; i < 6; i++)
            {
                Joy_serialPort.axes.push_back(Axies[i]);
            }
            for (int j = 0; j < 12; j++)
            {
                Joy_serialPort.buttons.push_back(buttons[j]);
            }

            Joy_last=Joy_serialPort;

            Joy_pub.publish(Joy_last);
        }
    ros::spinOnce();
    loop_rate.sleep();
    }
    return 0;
}
