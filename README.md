# xRobot_ws
xx机器人项目ROS代码

## 主从机设置
https://blog.csdn.net/zhanghm1995/article/details/106781954

## 关于罗技手柄的键位设置及上下位机文档见：
- https://shimo.im/docs/B5Wv6rrQyQICc7ft/ 《遥操控手柄指令重构-1203》，可复制链接后用石墨文档 App 或小程序打开

## 程序架构
1. 输入遥控指令模块
    - 遥控手柄驱动
    - 手柄信息提取解析，发布到话题之上
2. 小车底盘控制模块
    - 解析下层工控机上传数据
    - 发送控制指令给下层工控机


## 使用方法

```
#启动底盘节点
roslaunch xqserial_server xqserial.launch

#启动遥控节点
roslaunch jyr meizhong_joystick_teleop.launch

```

## GPS模块读取功能包 nmea_navsat_driver
参考：http://wiki.ros.org/nmea_navsat_driver

```
#使用方法（需要运行roscore）
$ rosrun nmea_navsat_driver nmea_serial_driver _port:=/dev/ttyUSB0 _baud:=38400
```

- GPS信号话题：/fix


## IMU和地磁场模块读取功能包 imu_driver
参考：https://github.com/GuoLindong/imu_driver
```
#使用方法
roslaunch imu_driver imu_node.launch
```
- 地磁信号话题： /mag
- IMU信号话题： /imu

## 摄像头与输送带控制功能包 communication_test
```
#使用方法
rosrun communication_test send_data_serialPort
```
注意问题：需要查看所接入的串口号为 /dev/ttyUSB1
