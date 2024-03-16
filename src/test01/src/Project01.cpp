// 自定义控制节点使乌龟做圆周运动

// 获取话题 /turtle1/cmd_vel
// 话题消息格式 geometry_msgs/Twist
/*
    话题消息内容
    geometry_msgs/Vector3 linear
  float64 x
  float64 y
  float64 z
    geometry_msgs/Vector3 angular
  float64 x
  float64 y
  float64 z
*/

// 包含头文件
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // ROS节点初始化
    ros::init(argc,argv,"control");
    // 实例化句柄
    ros::NodeHandle nh;
    // 创建发布者对象
    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1000);
    // 编辑发布信息
    geometry_msgs::Twist msg;
    msg.linear.x=1.0;
    msg.linear.y=0.0;
    msg.linear.z=0.0;

    msg.angular.x=0.0;
    msg.angular.y=0.0;
    msg.angular.z=2.0;
    // 设置发布逻辑
    ros::Rate r(10);

    while (ros::ok())
    {
        pub.publish(msg);
        r.sleep();
    }
    
    return 0;
}

