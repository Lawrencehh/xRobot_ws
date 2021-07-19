#include "StatusPublisher.h"
#include "AsyncSerial.h"
#include <memory.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#define DISABLE 0
#define ENABLE 1

namespace xqserial_server
{
typedef sensor_msgs::PointCloud2 PointCloud;

StatusPublisher::StatusPublisher()
{
    raw_Encorder_linearModule=0;
    raw_Hall_putter_1_left=0;
    raw_Hall_putter_1_right=0;
    raw_Hall_putter_2_left=0;
    raw_Hall_putter_2_right=0;
    raw_Hall_putter_3_left=0;
    raw_Hall_putter_3_right=0;

    pre_raw_Encorder_linearModule=0;
    pre_raw_Hall_putter_1_left=0;
    pre_raw_Hall_putter_1_right=0;
    pre_raw_Hall_putter_2_left=0;
    pre_raw_Hall_putter_2_right=0;
    pre_raw_Hall_putter_3_left=0;
    pre_raw_Hall_putter_3_right=0;

    func_motors_feedback.Encorder_linearModule=0;
    func_motors_feedback.Hall_putter_1_left=0;
    func_motors_feedback.Hall_putter_1_right=0;
    func_motors_feedback.Hall_putter_2_left=0;
    func_motors_feedback.Hall_putter_2_right=0;
    func_motors_feedback.Hall_putter_3_left=0;
    func_motors_feedback.Hall_putter_3_right=0;

    mbUpdated=false;

    CarPower.data = 0.0;

    reset_flag=0;

    int i=0;
    int * status;
    status=(int *)&car_status;
    for(i=0;i<23;i++)
    {
        status[i]=0;
    }
    //car_status.encoder_ppr=50556;//4*12*64;

  //  mPose2DPub = mNH.advertise<geometry_msgs::Pose2D>("xqserial_server/Pose2D",1,true);
   mStatusFlagPub = mNH.advertise<std_msgs::Int32>("xqserial_server/StatusFlag",1,true);
  //  mTwistPub = mNH.advertise<geometry_msgs::Twist>("xqserial_server/Twist",1,true);
   mPowerPub = mNH.advertise<std_msgs::Float64>("xqserial_server/Power", 1, true);

  //直线模组编码器及六个霍尔传感器数据话题发布
  mFunc_motors_feedbackPub=mNH.advertise<communication_test::func_motors_feedback>("xqserial_server/func_motors_feedback",1,true);

  //手柄话题的订阅
  mJoy = mNH.subscribe("joy", 1, &StatusPublisher::resetCallback,this);

   base_time_ = ros::Time::now().toSec();
}

StatusPublisher::StatusPublisher(double separation,double radius)
{
    new (this)StatusPublisher();
    wheel_separation=separation;
    wheel_radius=radius;
}

//清零回调函数
void StatusPublisher::resetCallback(const sensor_msgs::Joy::ConstPtr& joy){
  // if(joy->buttons[4]==1 && joy->buttons[1]==1 && joy->buttons[6]==1 && joy->axes[4]==1 ){
  if(joy->buttons[1]==1 && joy->buttons[4]==1 && joy->buttons[6]==1){ //按下 使能、自动轨迹规划、输送带使能，进行清零操作
    raw_Encorder_linearModule=0;
    raw_Hall_putter_1_left=0;
    raw_Hall_putter_1_right=0;
    raw_Hall_putter_2_left=0;
    raw_Hall_putter_2_right=0;
    raw_Hall_putter_3_left=0;
    raw_Hall_putter_3_right=0;

    pre_raw_Encorder_linearModule=0;
    pre_raw_Hall_putter_1_left=0;
    pre_raw_Hall_putter_1_right=0;
    pre_raw_Hall_putter_2_left=0;
    pre_raw_Hall_putter_2_right=0;
    pre_raw_Hall_putter_3_left=0;
    pre_raw_Hall_putter_3_right=0;

    func_motors_feedback.Encorder_linearModule=0;
    func_motors_feedback.Hall_putter_1_left=0;
    func_motors_feedback.Hall_putter_1_right=0;
    func_motors_feedback.Hall_putter_2_left=0;
    func_motors_feedback.Hall_putter_2_right=0;
    func_motors_feedback.Hall_putter_3_left=0;
    func_motors_feedback.Hall_putter_3_right=0;
    mFunc_motors_feedbackPub.publish(func_motors_feedback); //发布处理后的传感信号
    ROS_INFO_STREAM("Reset success!!!");
    reset_flag=1;
  }
  else reset_flag=0;

}

//***********************上位机解析下位机数据函数**************************//
void StatusPublisher::Update(const char data[], unsigned int len)
{
  // if(len <1) return;
  // static char data2[1024];
  // static int len2=0;
    boost::mutex::scoped_lock lock(mMutex);

    int i=0,j=0;
    int * receive_byte;
    static unsigned char last_str[2]={0x00,0x00};
    static unsigned char new_packed_ctr=DISABLE;//ENABLE表示新包开始，DISABLE 表示上一个包还未处理完；
    static int new_packed_ok_len=0;//包的理论长度
    static int new_packed_len=0;//包的实际长度
    static unsigned char cmd_string_buf[512];
    unsigned char current_str=0x00;
    const int cmd_string_max_size=512;
    receive_byte=(int *)&car_status;


//************************************上位机解析下位机数据*********************************//
    for(i=0;i<len;i++)
    {
        current_str=data[i];
       // unsigned int temp=(unsigned int)current_str;
       // std::cout<<temp<<std::endl;
        //判断是否有新包头
      if(last_str[0]==205&&last_str[1]==235&&current_str==215) //包头 205 235 215
        {
            //std::cout<<"runup1 "<<std::endl;
            new_packed_ctr=ENABLE;
            new_packed_ok_len=0;
            new_packed_len=new_packed_ok_len;
            last_str[0]=last_str[1];//保存最后两个字符，用来确定包头
            last_str[1]=current_str;
            continue;
        }
        last_str[0]=last_str[1];//保存最后两个字符，用来确定包头
        last_str[1]=current_str;
        if (new_packed_ctr==ENABLE)
        {

            //获取包长度
            new_packed_ok_len=current_str;
            if(new_packed_ok_len>cmd_string_max_size) new_packed_ok_len=cmd_string_max_size; //包内容最大长度有限制
            new_packed_ctr=DISABLE;
            //std::cout<<"runup2 "<< new_packed_len<< new_packed_ok_len<<std::endl;
        }
        else
        {
            //判断包当前大小
            if(new_packed_ok_len<=new_packed_len)
            {
                //std::cout<<"runup3 "<< new_packed_len<< new_packed_ok_len<<std::endl;
                //包长度已经大于等于理论长度，后续内容无效
                continue;
            }
            else
            {
                //获取包内容
                new_packed_len++;
                cmd_string_buf[new_packed_len-1]=current_str;
                if(new_packed_ok_len==new_packed_len&&new_packed_ok_len>0)
                {
                    // std::cout<<"runup4 "<<std::endl;
                    //当前包已经处理完成，开始处理
                    if(new_packed_ok_len==65)
                    {
                        for(j=0;j<13;j++)
                        {
                            memcpy(&receive_byte[j],&cmd_string_buf[5*j],4);

                        }
                        mbUpdated=true;
                    }
                    // else if(new_packed_ok_len==95)
                    // {
                    //     for(j=0;j<19;j++)
                    //     {
                    //         memcpy(&receive_byte[j],&cmd_string_buf[5*j],4);
                    //     }
                    //     mbUpdated=true;
                    // }
                    if(mbUpdated)
                    {
                      for(j=0;j<7;j++)
                      {
                          if(cmd_string_buf[5*j+4]!=32)
                          {

                            mbUpdated=false;

                            break;
                          }
                      }
                    }
                    if(mbUpdated)
                    {
                        base_time_ = ros::Time::now().toSec();
                    }

                    new_packed_ok_len=0;
                    new_packed_len=0;
                }
            }

        }

    }
    // for(j=0;j<len;j++)
    // {
    //   len2++;12
    //   if(len2==1024) len2=1;
    //   data2[len2-1]=data[j];
    // }

      //取得上一个时刻的传感数据
      pre_raw_Encorder_linearModule=raw_Encorder_linearModule;
      pre_raw_Hall_putter_1_left=raw_Hall_putter_1_left;
      pre_raw_Hall_putter_1_right=raw_Hall_putter_1_right;
      pre_raw_Hall_putter_2_left=raw_Hall_putter_2_left;
      pre_raw_Hall_putter_2_right=raw_Hall_putter_2_right;
      pre_raw_Hall_putter_3_left=raw_Hall_putter_3_left;
      pre_raw_Hall_putter_3_right=raw_Hall_putter_3_right;
      //取得该时刻的传感数据
      raw_Encorder_linearModule=car_status.encoder_linearModule=car_status.encoder_linearModule;
      raw_Hall_putter_1_left=car_status.hall_l_1=car_status.hall_l_1;
      raw_Hall_putter_1_right=car_status.hall_r_1=car_status.hall_r_1;
      raw_Hall_putter_2_left=car_status.hall_l_2=car_status.hall_l_2;
      raw_Hall_putter_2_right=car_status.hall_r_2=car_status.hall_r_2;
      raw_Hall_putter_3_left=car_status.hall_l_3=car_status.hall_l_3;
      raw_Hall_putter_3_right=car_status.hall_r_3=car_status.hall_r_3;
    return;
}


void StatusPublisher::Refresh()
{
     boost::mutex::scoped_lock lock(mMutex);

     static bool theta_updateflag = false;

     static int flag=0;


    if(mbUpdated)
    {
      // Time
      ros::Time current_time;

      if(car_status.status == 0)
      {
        theta_updateflag = false;
      }
      else
      {
        theta_updateflag = true;
      }

      //测试carpower和Encorder_linearModule的数值
      CarPower.data=car_status.power;
      mPowerPub.publish(CarPower);


      if(reset_flag == 0){
        //反馈信号集成
      //直线模组编码器值发布
      //大臂推杆霍尔传感器话题发布
      //小臂推杆霍尔传感器话题发布
      //斜板推杆霍尔传感器话题发布

      //直线模组编码器值发布
      // if((raw_Encorder_linearModule-pre_raw_Encorder_linearModule)>30000) func_motors_feedback.Encorder_linearModule +=(raw_Encorder_linearModule-pre_raw_Encorder_linearModule)-65536;
      // if((raw_Encorder_linearModule-pre_raw_Encorder_linearModule)<-30000) func_motors_feedback.Encorder_linearModule +=(raw_Encorder_linearModule-pre_raw_Encorder_linearModule)+65536;
      // if((raw_Encorder_linearModule-pre_raw_Encorder_linearModule)>-30000 && (raw_Encorder_linearModule-pre_raw_Encorder_linearModule)<30000 )
      func_motors_feedback.Encorder_linearModule +=(raw_Encorder_linearModule-pre_raw_Encorder_linearModule);
      // func_motors_feedback.Encorder_linearModule = raw_Encorder_linearModule;

      //大臂推杆霍尔传感器话题发布
      if((raw_Hall_putter_1_left-pre_raw_Hall_putter_1_left)>30000) func_motors_feedback.Hall_putter_1_left +=(raw_Hall_putter_1_left-pre_raw_Hall_putter_1_left)-65535;
      if((raw_Hall_putter_1_left-pre_raw_Hall_putter_1_left)<-30000) func_motors_feedback.Hall_putter_1_left +=(raw_Hall_putter_1_left-pre_raw_Hall_putter_1_left)+65535;
      if((raw_Hall_putter_1_left-pre_raw_Hall_putter_1_left)>-30000 && (raw_Hall_putter_1_left-pre_raw_Hall_putter_1_left)<30000 )
      func_motors_feedback.Hall_putter_1_left +=(raw_Hall_putter_1_left-pre_raw_Hall_putter_1_left);

      if((raw_Hall_putter_1_right-pre_raw_Hall_putter_1_right)>30000) func_motors_feedback.Hall_putter_1_right +=(raw_Hall_putter_1_right-pre_raw_Hall_putter_1_right)-65535;
      if((raw_Hall_putter_1_right-pre_raw_Hall_putter_1_right)<-30000) func_motors_feedback.Hall_putter_1_right +=(raw_Hall_putter_1_right-pre_raw_Hall_putter_1_right)+65535;
      if((raw_Hall_putter_1_right-pre_raw_Hall_putter_1_right)>-30000 && (raw_Hall_putter_1_right-pre_raw_Hall_putter_1_right)<30000 )
      func_motors_feedback.Hall_putter_1_right +=(raw_Hall_putter_1_right-pre_raw_Hall_putter_1_right);      

      //小臂推杆霍尔传感器话题发布
      if((raw_Hall_putter_2_left-pre_raw_Hall_putter_2_left)>30000) func_motors_feedback.Hall_putter_2_left +=(raw_Hall_putter_2_left-pre_raw_Hall_putter_2_left)-65535;
      if((raw_Hall_putter_2_left-pre_raw_Hall_putter_2_left)<-30000) func_motors_feedback.Hall_putter_2_left +=(raw_Hall_putter_2_left-pre_raw_Hall_putter_2_left)+65535;
      if((raw_Hall_putter_2_left-pre_raw_Hall_putter_2_left)>-30000 && (raw_Hall_putter_2_left-pre_raw_Hall_putter_2_left)<30000 )
      func_motors_feedback.Hall_putter_2_left +=(raw_Hall_putter_2_left-pre_raw_Hall_putter_2_left);

      if((raw_Hall_putter_2_right-pre_raw_Hall_putter_2_right)>30000) func_motors_feedback.Hall_putter_2_right +=(raw_Hall_putter_2_right-pre_raw_Hall_putter_2_right)-65535;
      if((raw_Hall_putter_2_right-pre_raw_Hall_putter_2_right)<-30000) func_motors_feedback.Hall_putter_2_right +=(raw_Hall_putter_2_right-pre_raw_Hall_putter_2_right)+65535;
      if((raw_Hall_putter_2_right-pre_raw_Hall_putter_2_right)>-30000 && (raw_Hall_putter_2_right-pre_raw_Hall_putter_2_right)<30000 )
      func_motors_feedback.Hall_putter_2_right +=(raw_Hall_putter_2_right-pre_raw_Hall_putter_2_right);

      //斜板推杆霍尔传感器话题发布
      if((raw_Hall_putter_3_left-pre_raw_Hall_putter_3_left)>30000) func_motors_feedback.Hall_putter_3_left +=(raw_Hall_putter_3_left-pre_raw_Hall_putter_3_left)-65535;
      if((raw_Hall_putter_3_left-pre_raw_Hall_putter_3_left)<-30000) func_motors_feedback.Hall_putter_3_left +=(raw_Hall_putter_3_left-pre_raw_Hall_putter_3_left)+65535;
      if((raw_Hall_putter_3_left-pre_raw_Hall_putter_3_left)>-30000 && (raw_Hall_putter_3_left-pre_raw_Hall_putter_3_left)<30000 )
      func_motors_feedback.Hall_putter_3_left +=(raw_Hall_putter_3_left-pre_raw_Hall_putter_3_left);

      if((raw_Hall_putter_3_right-pre_raw_Hall_putter_3_right)>30000) func_motors_feedback.Hall_putter_3_right +=(raw_Hall_putter_3_right-pre_raw_Hall_putter_3_right)-65535;
      if((raw_Hall_putter_3_right-pre_raw_Hall_putter_3_right)<-30000) func_motors_feedback.Hall_putter_3_right +=(raw_Hall_putter_3_right-pre_raw_Hall_putter_3_right)+65535;
      if((raw_Hall_putter_3_right-pre_raw_Hall_putter_3_right)>-30000 && (raw_Hall_putter_3_right-pre_raw_Hall_putter_3_right)<30000 )
      func_motors_feedback.Hall_putter_3_right +=(raw_Hall_putter_3_right-pre_raw_Hall_putter_3_right);
      }

      if(reset_flag ==1){
            raw_Encorder_linearModule=0;
            raw_Hall_putter_1_left=0;
            raw_Hall_putter_1_right=0;
            raw_Hall_putter_2_left=0;
            raw_Hall_putter_2_right=0;
            raw_Hall_putter_3_left=0;
            raw_Hall_putter_3_right=0;

            pre_raw_Encorder_linearModule=0;
            pre_raw_Hall_putter_1_left=0;
            pre_raw_Hall_putter_1_right=0;
            pre_raw_Hall_putter_2_left=0;
            pre_raw_Hall_putter_2_right=0;
            pre_raw_Hall_putter_3_left=0;
            pre_raw_Hall_putter_3_right=0;

            func_motors_feedback.Encorder_linearModule=0;
            func_motors_feedback.Hall_putter_1_left=0;
            func_motors_feedback.Hall_putter_1_right=0;
            func_motors_feedback.Hall_putter_2_left=0;
            func_motors_feedback.Hall_putter_2_right=0;
            func_motors_feedback.Hall_putter_3_left=0;
            func_motors_feedback.Hall_putter_3_right=0;
      }
      

      mFunc_motors_feedbackPub.publish(func_motors_feedback); //发布处理后的传感信号


        //flag
        std_msgs::Int32 flag;
        flag.data=car_status.status;

        ros::spinOnce();

        mbUpdated = false;
    }
}

double StatusPublisher::get_wheel_separation(){
    return wheel_separation;
}

double StatusPublisher::get_wheel_radius(){
    return wheel_radius;
}

int StatusPublisher::get_wheel_ppr(){
    //return car_status.encoder_ppr;
    return 50556;
}

void StatusPublisher::get_wheel_speed(double speed[2]){
    //右一左二
    //speed[0]=car_status.omga_r/car_status.encoder_ppr*2.0*PI*wheel_radius;
    //speed[1]=car_status.omga_l/car_status.encoder_ppr*2.0*PI*wheel_radius;
  speed[0]=car_status.omga_r/50556*2.0*PI*wheel_radius;
  speed[1]=car_status.omga_l/50556*2.0*PI*wheel_radius;

}

geometry_msgs::Pose2D StatusPublisher::get_CarPos2D(){
    return CarPos2D;
}

geometry_msgs::Twist StatusPublisher::get_CarTwist(){
    return CarTwist;
}

std_msgs::Float64 StatusPublisher::get_power(){
  return CarPower;
}

nav_msgs::Odometry StatusPublisher::get_odom(){
  return CarOdom;
}
int StatusPublisher::get_status(){

    return car_status.status=1;
}

} //namespace xqserial_server
