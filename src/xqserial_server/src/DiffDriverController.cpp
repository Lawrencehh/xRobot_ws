#include "DiffDriverController.h"
#include <time.h>
#include "turtlebot_teleop/twist_hh.h"  //引用自定义消息类型

namespace xqserial_server
{


DiffDriverController::DiffDriverController()
{
    max_wheelspeed=1.0;
    cmd_topic="cmd_vel";
    func_motors_topic="func_motors";
    xq_status=new StatusPublisher();
    cmd_serial=NULL;
    MoveFlag=true;
}

DiffDriverController::DiffDriverController(double max_speed_,std::string cmd_topic_,std::string func_motors_topic_,StatusPublisher* xq_status_,CallbackAsyncSerial* cmd_serial_)
{
    MoveFlag=true;
    max_wheelspeed=max_speed_;
    cmd_topic=cmd_topic_;
    func_motors_topic=func_motors_topic_;
    xq_status=xq_status_;
    cmd_serial=cmd_serial_;
}

void DiffDriverController::run()    //定义回调函数
{
    ros::NodeHandle nodeHandler;
    ros::Subscriber sub =  nodeHandler.subscribe(cmd_topic, 1, &DiffDriverController::sendcmd, this);
    ros::Subscriber sub2 = nodeHandler.subscribe("/imu_cal", 1, &DiffDriverController::imuCalibration,this);
    ros::Subscriber sub3 = nodeHandler.subscribe("/globalMoveFlag", 1, &DiffDriverController::updateMoveFlag,this);
    ros::Subscriber sub4 = nodeHandler.subscribe("/barDetectFlag", 1, &DiffDriverController::updateBarDetectFlag,this);
    ros::Subscriber sub5 = nodeHandler.subscribe(func_motors_topic, 1, &DiffDriverController::sendcmd_funcControl,this);
    ros::spin();
}

//定义除开底盘电机外的功能电机回调函数
void DiffDriverController::sendcmd_funcControl(const turtlebot_teleop::twist_hh& command)
{
    if(xq_status->get_status()==0) return;//底层还在初始化

    char cmd_str[25]={(char)0xcd,(char)0xeb,(char)0x13,(char)0x0d, (char)0x66, //包头和有效指令数, 0x13表示19个有效字符 最后一个字符是'f'表示控制功能电机
     (char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,             //直线模组,大臂推杆,小臂推杆控制
     (char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,             //斜板角度,斜板抽屉,伸缩柜
     (char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,             //输送带,摄像头旋转，摄像头俯仰
     (char)0x0d,(char)0x0a};                                                        //包尾

    
    double linear_module=0; //直线模组速度
    double putter_1=0;      //大臂电动推杆
    double putter_2=0;      //小臂电动推杆

    double oblique_angle=0;     //斜板角度
    double oblique_drawer=0;    //斜板抽屉
    double flat_drawer=0;       //伸缩柜伸展

    double belt=0;              //输送带
    double camera_angle=0;      //摄像头旋转
    double camera_tilt=0;       //摄像头俯仰

    

    linear_module=command.linear_module;    //直线模组
    putter_1=command.putter_1;         //大臂推杆
    putter_2=command.putter_2;         //小臂推杆

    oblique_angle=command.oblique_angle;    //斜板角度
    oblique_drawer=command.oblique_drawer;  //斜板抽屉
    flat_drawer=command.flat_drawer;        //伸缩柜伸展

    belt=command.belt;                      //输送带
    camera_angle=command.camera_angle;           //摄像头的旋转
    camera_tilt=command.camera_tilt;        //摄像头俯仰



/***************直线模组**********************/
    if(linear_module<0)
         {
             cmd_str[5]=(char)0x42;//B
             cmd_str[6]=-linear_module;
         }
         else if(linear_module>0)
         {
             cmd_str[5]=(char)0x46;//F
             cmd_str[6]=linear_module;
         }
         else
         {
             cmd_str[5]=(char)0x53;//S
             cmd_str[6]=(char)0x00;
         }
/***************直线模组**********************/

/***************大臂推杆**********************/
    if(putter_1<0)
         {
             cmd_str[7]=(char)0x42;//B
             cmd_str[8]=-putter_1;
         }
         else if(putter_1>0)
         {
             cmd_str[7]=(char)0x46;//F
             cmd_str[8]=putter_1;
         }
         else
         {
             cmd_str[7]=(char)0x53;//S
             cmd_str[8]=(char)0x00;
         }
/***************大臂推杆**********************/

/***************小臂推杆**********************/
    if(putter_2<0)
         {
             cmd_str[9]=(char)0x42;//B
             cmd_str[10]=-putter_2;
         }
         else if(putter_2>0)
         {
             cmd_str[9]=(char)0x46;//F
             cmd_str[10]=putter_2;
         }
         else
         {
             cmd_str[9]=(char)0x53;//S
             cmd_str[10]=(char)0x00;
         }
/***************小臂推杆**********************/

/*****************斜板角度********************/
    if(oblique_angle<0)
         {
             cmd_str[11]=(char)0x42;//B
             cmd_str[12]=-oblique_angle;
         }
         else if(oblique_angle>0)
         {
             cmd_str[11]=(char)0x46;//F
             cmd_str[12]=oblique_angle;
         }
         else
         {
             cmd_str[11]=(char)0x53;//S
             cmd_str[12]=(char)0x00;
         }
/*****************斜板角度********************/

/*****************斜板抽屉********************/
    if(oblique_drawer<0)
         {
             cmd_str[13]=(char)0x42;//B
             cmd_str[14]=-oblique_drawer;
         }
         else if(oblique_drawer>0)
         {
             cmd_str[13]=(char)0x46;//F
             cmd_str[14]=oblique_drawer;
         }
         else
         {
             cmd_str[13]=(char)0x53;//S
             cmd_str[14]=(char)0x00;
         }
/*****************斜板抽屉********************/


/*****************伸缩柜伸展********************/
    if(flat_drawer<0)
         {
             cmd_str[15]=(char)0x42;//B
             cmd_str[16]=-flat_drawer;
         }
         else if(flat_drawer>0)
         {
             cmd_str[15]=(char)0x46;//F
             cmd_str[16]=flat_drawer;
         }
         else
         {
             cmd_str[15]=(char)0x53;//S
             cmd_str[16]=(char)0x00;
         }

/*****************伸缩柜伸展********************/


/*****************输送带********************/
    if(belt<0)
         {
             cmd_str[17]=(char)0x42;//B
             cmd_str[18]=-belt;
         }
         else if(belt>0)
         {
             cmd_str[17]=(char)0x46;//F
             cmd_str[18]=belt;
         }
         else
         {
             cmd_str[17]=(char)0x53;//S
             cmd_str[18]=(char)0x00;
         }

/*****************输送带********************/

/***************摄像头**********************/
    if(camera_angle<0)
         {
             cmd_str[19]=(char)0x42;//B 顺时针
             cmd_str[20]=-camera_angle;
         }
         else if(camera_angle>0)
         {
             cmd_str[19]=(char)0x46;//F  逆时针
             cmd_str[20]=camera_angle;
         }
         else
         {
             cmd_str[19]=(char)0x53;//S
             cmd_str[20]=(char)0x00;
         }
/***************摄像头**********************/

/*****************摄像头俯仰********************/
    if(camera_tilt<0)
         {
             cmd_str[21]=(char)0x42;//B
             cmd_str[22]=-camera_tilt;
         }
         else if(camera_tilt>0)
         {
             cmd_str[21]=(char)0x46;//F
             cmd_str[22]=camera_tilt;
         }
         else
         {
             cmd_str[21]=(char)0x53;//S
             cmd_str[22]=(char)0x00;
         }
/*****************摄像头俯仰********************/


  boost::mutex::scoped_lock lock(mMutex);//???????这个需要查一下什么意思
   /* if(!MoveFlag)
    {
      cmd_str[5]=(char)0x53;
      cmd_str[6]=(char)0x53;
    }
    */
    if(NULL!=cmd_serial)
    {
        cmd_serial->write(cmd_str,25);
    }


}

void DiffDriverController::updateMoveFlag(const std_msgs::Bool& moveFlag)
{
  boost::mutex::scoped_lock lock(mMutex);
  MoveFlag=moveFlag.data;

}
void DiffDriverController::imuCalibration(const std_msgs::Bool& calFlag)
{
  if(calFlag.data)
  {
    //下发底层ｉｍｕ标定命令
    char cmd_str[5]={(char)0xcd,(char)0xeb,(char)0xd7,(char)0x01,(char)0x43};
    if(NULL!=cmd_serial)
    {
        cmd_serial->write(cmd_str,5);
    }
  }
}
void DiffDriverController::updateBarDetectFlag(const std_msgs::Bool& DetectFlag)
{
  if(DetectFlag.data)
  {
    //下发底层红外开启命令
    char cmd_str[6]={(char)0xcd,(char)0xeb,(char)0xd7,(char)0x02,(char)0x44,(char)0x01};
    if(NULL!=cmd_serial)
    {
        cmd_serial->write(cmd_str,6);
    }
  }
  else
  {
    //下发底层红外禁用命令
    char cmd_str[6]={(char)0xcd,(char)0xeb,(char)0xd7,(char)0x02,(char)0x44,(char)0x00};
    if(NULL!=cmd_serial)
    {
        cmd_serial->write(cmd_str,6);
    }
  }
}
void DiffDriverController::sendcmd(const geometry_msgs::Twist &command)
{
    static time_t t1=time(NULL),t2;
    int i=0,wheel_ppr=1;
    double separation=0,radius=0,speed_lin_x=0,speed_lin_y=0,speed_ang=0,speed_temp[4],w1=0,w2=0,w3=0,w4=0;


    char speed[2]={0,0};//右一左二


     char cmd_str[11]={(char)0xcd,(char)0xeb,(char)0xd7,(char)0x05, //包头和有效指令数
     (char)0x74,(char)0x00,(char)0x00,(char)0x00,(char)0x00,        //'t'字符,2个履带电机控制
     (char)0x0d,(char)0x0a};                                        //包尾
     //0xcd 0xeb 0xd7代表包头, 0x05表示之后有5个有效数据, 0x74(t字符)表示履带电机命令, 紧接着两个u8字符表示右轮和左轮的状态
     //F：向前，B：向后，S：刹车,F:0x46,B:0x42,S:0x53
     //再后两个为电机的速度等级，范围0～100,即以字符的数值表示速度
     //0x0d,0x0a为包尾部,表示命令的结束

    if(xq_status->get_status()==0) return;//底层还在初始化


    // ********************这里未用到**************************
    separation=xq_status->get_wheel_separation();
    radius=xq_status->get_wheel_radius();
    wheel_ppr=50556;//xq_status->get_wheel_ppr();
    //转换速度单位，由米转换成转
    //speed_lin=command.linear.x/(2.0*PI*radius);
    //speed_ang=command.angular.z*separation/(2.0*PI*radius);
    // ********************这里未用到**************************

    speed_lin_y=command.linear.x;       //底盘电机的前进后退
    speed_ang=command.angular.z;        //底盘电机的旋转
    

    // w1=speed_lin_x/(2.0*PI*0.2) + speed_ang*700.0/(4.0*PI*76.2); // 计算右轮
    // w2=speed_lin_x/(2.0*PI*0.2) - speed_ang*700.0/(4.0*PI*76.2);   //计算左轮

    w1=speed_lin_y + speed_ang * 0.5; // 计算右轮,这里和下面一样,将旋转变量乘了系数
    w2=speed_lin_y - speed_ang * 0.5;   //计算左轮



    
    //转出最大速度百分比,并进行限幅
    speed_temp[0]=w1/max_wheelspeed*100.0;
    speed_temp[0]=std::min(speed_temp[0],100.0);
    speed_temp[0]=std::max(-100.0,speed_temp[0]);

    speed_temp[1]=w2/max_wheelspeed*100.0;
    speed_temp[1]=std::min(speed_temp[1],100.0);
    speed_temp[1]=std::max(-100.0,speed_temp[1]);




  //std::cout<<"radius "<<radius<<std::endl;
  //std::cout<<"ppr "<<wheel_ppr<<std::endl;
  //std::cout<<"pwm "<<speed_temp[0]<<std::endl;


/***************履带电机**********************/
    for(i=0;i<2;i++)//右一左二
        {
         speed[i]=(int8_t)speed_temp[i];
         if(speed[i]<0)
         {
             cmd_str[5+i]=(char)0x42;//B
             cmd_str[7+i]=-speed[i];
         }
         else if(speed[i]>0)
         {
             cmd_str[5+i]=(char)0x46;//F
             cmd_str[7+i]=speed[i];
         }
         else
         {
             cmd_str[5+i]=(char)0x53;//S
             cmd_str[7+i]=(char)0x00;
         }
      }
/***************履带电机**********************/


  boost::mutex::scoped_lock lock(mMutex);
   /* if(!MoveFlag)
    {
      cmd_str[5]=(char)0x53;
      cmd_str[6]=(char)0x53;
    }
    */
    if(NULL!=cmd_serial)
    {
        cmd_serial->write(cmd_str,11);
    }

   // command.linear.x
}






















}
