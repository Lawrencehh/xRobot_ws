/*
 * Copyright (c) 2010, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include "boost/thread/mutex.hpp"
#include "boost/thread/thread.hpp"
#include "ros/console.h"
#include "turtlebot_teleop/twist_hh.h"  //引用自定义消息类型



class TurtlebotTeleop
{
public:
  TurtlebotTeleop();

private:
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
  void publish();

  ros::NodeHandle ph_, nh_;

  int linear_x, angular_, deadman_axis_; //履带底盘的按键设置
  int deadman_func_axis_;      //功能电机的使能

 

  int linear_module;  //线性模组电机前进后退的按键设置
  int putter_1;       //大臂电动推杆按键设置
  int putter_2;       //小臂电动推杆按键设置

  int oblique_angle1;  //斜板角度
  int oblique_angle2;  //斜板角度
  int oblique_drawer1; //斜板抽屉
  int oblique_drawer2; //斜板抽屉
  int flat_drawer1;    //伸缩柜控制
  int flat_drawer2;    //伸缩柜控制

  int belt;           //输送带控制

  int camera_angle;   //摄像头旋转
  int camera_tilt1;    //摄像头俯仰角
  int camera_tilt2;    //摄像头俯仰角


  double l_scale_x, l_scale_y, a_scale_;  //比例因子

  ros::Publisher vel_pub_;  //底盘电机速度topic发布

  ros::Publisher func_motors_pub_;  //所有电机状态发布

  ros::Subscriber joy_sub_;

  geometry_msgs::Twist last_published_;
  turtlebot_teleop::twist_hh last_pubulished_add;

  

  boost::mutex publish_mutex_;
  bool deadman_pressed_;
  bool deadman_func_pressed_;
  bool zero_twist_published_;
  bool zero_func_published_;
  ros::Timer timer_;

};

TurtlebotTeleop::TurtlebotTeleop():
  ph_("~"),
  linear_x(1),
  angular_(0),    //将罗技左摇杆的左右设置为旋转变量
  deadman_axis_(10), //履带电机使能键,这里设置的罗技的左摇杆按键
  deadman_func_axis_(6), //功能电机使能键,这里设置的罗技的LB键

  

  oblique_angle1(3),  //斜板角度
  oblique_angle2(1),  //斜板角度
  oblique_drawer1(2), //斜板抽屉
  oblique_drawer2(0), //斜板抽屉
  flat_drawer1(9),    //伸缩柜控制
  flat_drawer2(8),    //伸缩柜控制

  belt(4),           //输送带控制
  camera_tilt1(5),    //摄像头俯仰角
  camera_tilt2(7),    //摄像头俯仰角
  camera_angle(4),      //将罗技左上角方向键的左右设置为摄像头旋转

  linear_module(5), //线性模组设置为罗技左上角方向键的前后
  putter_1(3),      //大臂设置为罗技右摇杆的前后
  putter_2(2),      //小臂设置为罗技右摇杆的左右



  l_scale_x(0.3),
  l_scale_y(0.3),
  a_scale_(0.9)
{
  ph_.param("axis_linear_x", linear_x, linear_x);
  ph_.param("axis_angular", angular_, angular_);
  ph_.param("axis_deadman", deadman_axis_, deadman_axis_);
  ph_.param("axis_func_deadman", deadman_func_axis_, deadman_func_axis_);

  ph_.param("scale_angular", a_scale_, a_scale_);
  ph_.param("scale_linear_x", l_scale_x, l_scale_x);
  ph_.param("scale_linear_y", l_scale_y, l_scale_y);
  



  ph_.param("linear_module_", linear_module, linear_module);  //线性模组状态控制参数设置
  ph_.param("putter_1_", putter_1, putter_1);  //大臂电动推杆控制参数设置
  ph_.param("putter_2_", putter_2, putter_2);  //小臂电动推杆控制参数设置

  ph_.param("oblique_angle1_", oblique_angle1, oblique_angle1);  //斜板角度推杆伸长
  ph_.param("oblique_angle2_", oblique_angle2, oblique_angle2);  //斜板角度推杆缩短
  ph_.param("oblique_drawer1_", oblique_drawer1, oblique_drawer1);  //斜板抽屉推杆伸长
  ph_.param("oblique_drawer2_", oblique_drawer2, oblique_drawer2);  //斜板抽屉推杆缩短
  ph_.param("flat_drawer1_", flat_drawer1, flat_drawer1);  //伸缩柜抽屉伸展
  ph_.param("flat_drawer2_", flat_drawer2, flat_drawer2);  //伸缩柜抽屉缩回
  ph_.param("belt_", belt, belt);  //输送带动作
  ph_.param("camera_angle_", camera_angle, camera_angle);  //摄像头旋转参数设置
  ph_.param("camera_tilt1_", camera_tilt1, camera_tilt1);  //摄像头俯仰角上扬
  ph_.param("camera_tilt2_", camera_tilt2, camera_tilt2);  //摄像头俯仰角上扬
  

  deadman_pressed_ = false;
  deadman_func_pressed_ = false;
  zero_twist_published_ = false;
  zero_func_published_ = false;

  vel_pub_ = ph_.advertise<geometry_msgs::Twist>("cmd_vel", 1, true); //所有电机的状态发布
  func_motors_pub_ = ph_.advertise<turtlebot_teleop::twist_hh>("func_motors",1,true); //所有电机的状态发布

  joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TurtlebotTeleop::joyCallback, this);


  timer_ = nh_.createTimer(ros::Duration(0.1), boost::bind(&TurtlebotTeleop::publish, this));
}

void TurtlebotTeleop::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{ 
  geometry_msgs::Twist vel;
  turtlebot_teleop::twist_hh func_motors;
  
  vel.linear.x = l_scale_x*joy->axes[linear_x]; //底盘的前进后退
  vel.angular.z = a_scale_*joy->axes[angular_]; //底盘的旋转
  



  func_motors.linear_module = joy->axes[linear_module]; //线性模组的前进后退
  func_motors.putter_1 = joy->axes[putter_1]; //大臂
  func_motors.putter_2 = joy->axes[putter_2]; //小臂
  
  func_motors.oblique_angle = joy->buttons[oblique_angle1] - joy->buttons[oblique_angle2]; //斜板角度推杆控制
  func_motors.oblique_drawer = joy->buttons[oblique_drawer1] - joy->buttons[oblique_drawer2]; //斜板抽屉推杆控制
  func_motors.flat_drawer = joy->buttons[flat_drawer1] - joy->buttons[flat_drawer2]; //伸缩柜伸展控制

  func_motors.belt = joy->buttons[belt]; //输送带动作控制
  func_motors.camera_angle = joy->axes[camera_angle];  //摄像头的旋转
  func_motors.camera_tilt = joy->buttons[camera_tilt1] - joy->buttons[camera_tilt2]; //摄像头俯仰角控制



  

  last_published_ = vel;
  last_pubulished_add = func_motors;    //加一个临时值存放
  deadman_pressed_ = joy->buttons[deadman_axis_];
  deadman_func_pressed_ = joy->buttons[deadman_func_axis_];
  
}

void TurtlebotTeleop::publish()
{
  boost::mutex::scoped_lock lock(publish_mutex_);

  if (deadman_pressed_)
  {
    vel_pub_.publish(last_published_);
    // func_motors_pub_.publish(last_pubulished_add);    //发布功能电机控制话题
    zero_twist_published_=false;
  }
  else if(!deadman_pressed_ && !zero_twist_published_)
  {
    vel_pub_.publish(*new geometry_msgs::Twist());
    // func_motors_pub_.publish(*new turtlebot_teleop::twist_hh());    //第一次时发布空话题
    zero_twist_published_=true;
  }

    if (deadman_func_pressed_)
  {
    // vel_pub_.publish(last_published_);
    func_motors_pub_.publish(last_pubulished_add);    //发布功能电机控制话题
    zero_func_published_=false;
  }
  else if(!deadman_func_pressed_ && !zero_func_published_)
  {
    // vel_pub_.publish(*new geometry_msgs::Twist());
    func_motors_pub_.publish(*new turtlebot_teleop::twist_hh());    //第一次时发布空话题
    zero_func_published_=true;
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "meizhong_teleop");
  TurtlebotTeleop turtlebot_teleop;

  ros::spin();
}
