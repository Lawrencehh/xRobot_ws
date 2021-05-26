
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

//CRC8校验
unsigned char Get_Crc8(unsigned char *ptr,int LEN)
{
    int i;
    unsigned char crc;
    crc=0;
    while(LEN--)
    {
        crc^=*ptr++;
        for(i=0;i<8;i++)
        {
            if(crc&0x01) crc=(crc>>1)^0x31;
            else crc >>= 1;
        }
    }
    return crc;
};

//将串口数据转为twist数据和cmd_vel数据
void CopeSerialData(std::string str_in)
{
    unsigned int str_length = str_in.size();
    static unsigned char chrTemp[20000];
    static unsigned int usRxLength = 0;
    int valid_length;  //有效代码长度

    memcpy(chrTemp,str_in.data(),str_length);
    usRxLength += str_length;

    Joy_serialPort.axes.clear();
    Joy_serialPort.buttons.clear();


    while (usRxLength >= 12) //之前数据为12
    {
       
        if (chrTemp[0] != 0x7F && chrTemp[0] != 0x8F )    //帧头
        {
            usRxLength--;
            memcpy(&chrTemp[0],&chrTemp[1],usRxLength);
            continue;
        }

        //MCU1的数据处理
        if (chrTemp[0] == 0x7F ) //MCU1帧头
        {   
            ROS_INFO_STREAM("usRxLength:"<<usRxLength);
            switch(chrTemp[2])//0x0D为手柄协议，0x0C为按键协议，0x09为旋钮
            {
                
                case 0x0D:	
                {
                    ROS_INFO_STREAM("chrTemp[2]:"<<(int)chrTemp[2]);
                    valid_length = 10;//有效协议长度为10

                    unsigned char *ptr1[valid_length-1];
                    for (int i = 0; i < valid_length-1; i++)
                    {
                        ptr1[i]=&chrTemp[i];
                    }
                    
                    if(Get_Crc8(*ptr1,valid_length-1) == chrTemp[valid_length-1])   //检验CRC是否准确，若不准确，则不进行赋值处理。
                    {
                        if(chrTemp[4]==0x01){   //将左侧摇杆赋值给Axies[0],Axies[1]
                            Axies[0]=(float)-1/480*(256.0*(int)chrTemp[5]+(int)chrTemp[6]-512);
                            Axies[1]=(float)1/480*(256.0*(int)chrTemp[7]+(int)chrTemp[8]-512);
                        }
                        if(chrTemp[4]==0x02){   //将右侧摇杆赋值给Axies[2],Axies[3]
                            Axies[2]=(float)1/480*(256.0*(int)chrTemp[7]+(int)chrTemp[8]-512);
                            Axies[3]=(float)1/480*(256.0*(int)chrTemp[5]+(int)chrTemp[6]-512);
                        }
                        ROS_INFO_STREAM("Joysticks1 CRC success!");
                    }
                    else ROS_INFO_STREAM("Joysticks1 CRC failed!");

                    usRxLength -= 10;
                    memcpy(&chrTemp[0],&chrTemp[valid_length],usRxLength); //将已经处理完的数据推出队列
                    break;
                }

                case 0x0C:
                {
                    valid_length = 12;//有效协议长度为12
                    unsigned char *ptr1[valid_length-1];
                    for (int i = 0; i < valid_length-1; i++)
                    {
                        ptr1[i]=&chrTemp[i];
                    }

                    if(Get_Crc8(*ptr1,valid_length-1) == chrTemp[valid_length-1])   //检验CRC是否准确，若不准确，则不进行赋值处理。
                    {
                        buttons[5] = 1-(int)chrTemp[9];    //左侧摇杆按钮，控制摄像头向上

                        // buttons[10] = 1-(int)chrTemp[7];    //急停按钮，底盘使能
                        // buttons[6] = 1-(int)chrTemp[7];     //急停按钮，功能电机使能

                        // buttons[7] = 1-(int)chrTemp[10];    //右侧摇杆按钮，控制摄像头向下

                        // buttons[4] = 1-(int)chrTemp[6];     //控制启动指令按钮，输送带使能

                        // buttons[1] = 1-(int)chrTemp[8];     //机械臂自动轨迹规划按钮，自动轨迹规划使能

                        ROS_INFO_STREAM("Buttons1 CRC success!");
                    }
                    else ROS_INFO_STREAM("Buttons1 CRC failed!");
                    
                    usRxLength -= 12;
                    memcpy(&chrTemp[0],&chrTemp[valid_length],usRxLength); //将已经处理完的数据推出队列
                    break;
                }

                case 0x09:
                {
                    
                    valid_length = 9;//有效协议长度为9
                    unsigned char *ptr1[valid_length-1];
                    for (int i = 0; i < valid_length-1; i++)
                    {
                        ptr1[i]=&chrTemp[i];
                    }

                    if(Get_Crc8(*ptr1,valid_length-1) == chrTemp[valid_length-1])   //检验CRC是否准确，若不准确，则不进行赋值处理
                    {
                        //第5个旋钮，作为摄像头的旋转
                        if((int)chrTemp[6]>10){
                            buttons[5] = 1;
                            buttons[7] = 0;
                        }
                        if((int)chrTemp[6]<5){
                            buttons[5] = 0;
                            buttons[7] = 1;
                        }
                        if((int)chrTemp[6]<=10 && (int)chrTemp[6]>=5){
                            buttons[5] = 0;
                            buttons[7] = 0;
                        }

                        ROS_INFO_STREAM("Knobs1 CRC success!");
                    }
                    else ROS_INFO_STREAM("Knobs1 CRC failed!");
                    

                    usRxLength -= 9;
                    memcpy(&chrTemp[0],&chrTemp[valid_length],usRxLength); //将已经处理完的数据推出队列
                    break;
                }

                default: //如果协议不对，直接删除这几个字符
                {
                    usRxLength--;
                    memcpy(&chrTemp[0],&chrTemp[1],usRxLength);
                    break;
                }

            }
        }

        
        //MCU2数据处理
        if (chrTemp[0] == 0x8F ) //MUC2帧头
        {   
            ROS_INFO_STREAM("usRxLength:"<<usRxLength);
            switch(chrTemp[2])//0x0D为手柄协议，0x0C为按键协议，0x09为旋钮
            {
                
                case 0x0D:	
                {
                    ROS_INFO_STREAM("chrTemp[2]:"<<(int)chrTemp[2]);
                    valid_length = 10;//有效协议长度为10

                    unsigned char *ptr1[valid_length-1];
                    for (int i = 0; i < valid_length-1; i++)
                    {
                        ptr1[i]=&chrTemp[i];
                    }
                    
                    if(Get_Crc8(*ptr1,valid_length-1) == chrTemp[valid_length-1])   //检验CRC是否准确，若不准确，则不进行赋值处理。
                    {
                        if(chrTemp[4]==0x01){   //将左侧摇杆赋值给Axies[0],Axies[1]
                            Axies[0]=(float)-1/480*(256.0*(int)chrTemp[5]+(int)chrTemp[6]-512);
                            Axies[1]=(float)1/480*(256.0*(int)chrTemp[7]+(int)chrTemp[8]-512);
                        }
                        if(chrTemp[4]==0x02){   //将右侧摇杆赋值给Axies[2],Axies[3]
                            Axies[2]=(float)1/480*(256.0*(int)chrTemp[7]+(int)chrTemp[8]-512);
                            Axies[3]=(float)1/480*(256.0*(int)chrTemp[5]+(int)chrTemp[6]-512);
                        }
                        ROS_INFO_STREAM("Joysticks2 CRC success!");
                    }
                    else ROS_INFO_STREAM("Joysticks2 CRC failed!");
                    usRxLength -= 10;
                    memcpy(&chrTemp[0],&chrTemp[valid_length],usRxLength); //将已经处理完的数据推出队列
                    break;
                }

                case 0x0C:
                {
                    valid_length = 12;//有效协议长度为12
                    unsigned char *ptr1[valid_length-1];
                    for (int i = 0; i < valid_length-1; i++)
                    {
                        ptr1[i]=&chrTemp[i];
                    }

                    if(Get_Crc8(*ptr1,valid_length-1) == chrTemp[valid_length-1])   //检验CRC是否准确，若不准确，则不进行赋值处理。
                    {
                        // buttons[5] = 1-(int)chrTemp[9];    //左侧摇杆按钮，控制摄像头向上

                        buttons[10] = 1-(int)chrTemp[7];    //急停按钮，底盘使能
                        buttons[6] = 1-(int)chrTemp[7];     //急停按钮，功能电机使能

                        buttons[7] = 1-(int)chrTemp[10];    //右侧摇杆按钮，控制摄像头向下

                        buttons[4] = 1-(int)chrTemp[6];     //控制启动指令按钮，输送带使能

                        buttons[1] = 1-(int)chrTemp[8];     //机械臂自动轨迹规划按钮，自动轨迹规划使能

                        ROS_INFO_STREAM("Buttons2 CRC success!");
                    }
                    else ROS_INFO_STREAM("Buttons2 CRC failed!");
                    
                    usRxLength -= 12;
                    memcpy(&chrTemp[0],&chrTemp[valid_length],usRxLength); //将已经处理完的数据推出队列
                    break;
                }

                case 0x09:
                {
                    
                    
                    valid_length = 9;//有效协议长度为9
                    
                    unsigned char *ptr1[valid_length-1];
                    for (int i = 0; i < valid_length-1; i++)
                    {
                        ptr1[i]=&chrTemp[i];
                    }

                    if(Get_Crc8(*ptr1,valid_length-1) == chrTemp[valid_length-1])   //检验CRC是否准确，若不准确，则不进行赋值处理。
                    {
                        //第1个旋钮，作为直线模组的前进后退
                        if((int)chrTemp[6]>10){
                            Axies[5] = 1;
                        }
                        if((int)chrTemp[6]<5){
                            Axies[5] = -1;
                        }
                        if((int)chrTemp[6]<=10 && (int)chrTemp[6]>=5){
                            Axies[5] = 0;
                        }

                        //第4个旋钮，作为摄像头的旋转控制
                        if((int)chrTemp[3]>10){
                            Axies[4] = -1;
                        }
                        if((int)chrTemp[3]<5){
                            Axies[4] = 1;
                        }
                        if((int)chrTemp[3]<=10 && (int)chrTemp[3]>=5){
                            Axies[4] = 0;
                        }

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
                        if((int)chrTemp[4]<=10 && (int)chrTemp[4]>=5){
                            buttons[9] = 0;
                            buttons[8] = 0;
                            buttons[2] = 0;
                            buttons[0] = 0;
                        }
                        ROS_INFO_STREAM("Knobs2 CRC success!");
                    }
                    else ROS_INFO_STREAM("Knobs2 CRC failed!");
                    
                    usRxLength -= 9;
                    memcpy(&chrTemp[0],&chrTemp[valid_length],usRxLength); //将已经处理完的数据推出队列
                    break;
                }

                default: //如果协议不对，直接删除这几个字符
                {
                    usRxLength--;
                    memcpy(&chrTemp[0],&chrTemp[1],usRxLength);
                    break;
                }

            }
        }
 
        
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
    ser.setPort("/dev/xRobot-tele");


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

    ros::Rate loop_rate(20);
         

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

            // Joy_last=Joy_serialPort;

            Joy_pub.publish(Joy_serialPort);
        }
    ros::spinOnce();
    loop_rate.sleep();
    }
    return 0;
}
