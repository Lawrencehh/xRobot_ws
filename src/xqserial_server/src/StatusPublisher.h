#ifndef STATUSPUBLISHER_H
#define STATUSPUBLISHER_H

#include "ros/ros.h"
#include <boost/thread.hpp>
#include <boost/assign/list_of.hpp>
#include <algorithm>
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Vector3.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float64.h"
#include "tf/transform_broadcaster.h"
#include <sensor_msgs/point_cloud2_iterator.h>
#include <sensor_msgs/PointField.h>
#include <sensor_msgs/Imu.h>

#define PI 3.14159265

namespace xqserial_server
{
typedef struct {
    int status;//小车状态，0表示未初始化，1表示正常，-1表示error
    float power;//电源电压【9 13】v
    int encoder_delta_r;//右轮编码器增量， 个为单位
    int encoder_delta_l;//左轮编码器增量， 个为单位
    int omga_r;//右轮转速 个每秒
    int omga_l;//左轮转速 个每秒
    int encoder_linearModule;//直线模组编码器读数
    int hall_l_1;//左侧大臂推杆霍尔传感器读数
    int hall_r_1;//右侧大臂推杆霍尔传感器读数
    int hall_l_2;//左侧小臂推杆霍尔传感器读数
    int hall_r_2;//右侧小臂推杆霍尔传感器读数
    int hall_l_3;//左侧斜板推杆霍尔传感器读数
    int hall_r_3;//右侧斜板推杆霍尔传感器读数
}UPLOAD_STATUS;

class StatusPublisher
{

public:
    StatusPublisher();
    StatusPublisher(double separation,double radius);
    void Refresh();
    void Update(const char *data, unsigned int len);
    double get_wheel_separation();
    double get_wheel_radius();
    int get_wheel_ppr();
    int get_status();
    geometry_msgs::Pose2D get_CarPos2D();
    void get_wheel_speed(double speed[2]);
    geometry_msgs::Twist get_CarTwist();
    std_msgs::Float64 get_power();
    nav_msgs::Odometry get_odom();
    UPLOAD_STATUS car_status;

private:



    //Wheel separation, wrt the midpoint of the wheel width: meters
    double wheel_separation;

    //Wheel radius (assuming it's the same for the left and right wheels):meters
    double wheel_radius;

    geometry_msgs::Pose2D CarPos2D;//小车开始启动原点坐标系
    geometry_msgs::Twist  CarTwist;//小车自身坐标系
    std_msgs::Float64 CarPower;// 小车电池信息
    nav_msgs::Odometry CarOdom;// 小车位置和速度信息

    std_msgs::Int32 Encorder_linearModule;//直线模组编码器
    std_msgs::Int32 Hall_putter_1_left;     //左侧大臂推杆霍尔传感器
    std_msgs::Int32 Hall_putter_1_right;    //右侧大臂推杆霍尔传感器
    std_msgs::Int32 Hall_putter_2_left;     //左侧小臂推杆霍尔传感器
    std_msgs::Int32 Hall_putter_2_right;    //右侧小臂推杆霍尔传感器
    std_msgs::Int32 Hall_putter_3_left;     //左侧斜板推杆霍尔传感器
    std_msgs::Int32 Hall_putter_3_right;    //右侧斜板推杆霍尔传感器

    ros::NodeHandle mNH;
    ros::Publisher mPose2DPub;
    ros::Publisher mTwistPub;
    ros::Publisher mStatusFlagPub;
    ros::Publisher mPowerPub;
    ros::Publisher mOdomPub;
    ros::Publisher pub_barpoint_cloud_;
    ros::Publisher pub_clearpoint_cloud_;

    ros::Publisher mEncorder_linearModulePub;   //直线模组编码器话题发布
    ros::Publisher mHall_putter_1_leftPub;      //左侧大臂推杆霍尔传感器话题发布
    ros::Publisher mHall_putter_1_rightPub;     //右侧大臂推杆霍尔传感器话题发布
    ros::Publisher mHall_putter_2_leftPub;      //左侧小臂推杆霍尔传感器话题发布
    ros::Publisher mHall_putter_2_rightPub;     //右侧小臂推杆霍尔传感器话题发布
    ros::Publisher mHall_putter_3_leftPub;      //左侧斜板推杆霍尔传感器话题发布
    ros::Publisher mHall_putter_3_rightPub;     //右侧斜板推杆霍尔传感器话题发布



    bool mbUpdated;

    boost::mutex mMutex;
    double base_time_;

    ros::Publisher mIMUPub;
    sensor_msgs::Imu  CarIMU;
};

} //namespace xqserial_server


#endif // STATUSPUBLISHER_H
