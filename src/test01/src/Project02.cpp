// 时时获取乌龟的位置信息
// 获取话题 /turtle1/pose
// 话题消息格式 turtlesim/Pose
/*
    话题消息内容
    float32 x
    float32 y
    float32 theta
    float32 linear_velocity
    float32 angular_velocity
*/

// 引用头文件
#include "ros/ros.h"
#include "turtlesim/Pose.h"

// 消息处理函数
void doMsg(const turtlesim::Pose::ConstPtr& location)
{
    ROS_INFO("位置信息:x=%.2f,y=%.2f,theta=%.2f,lv=%.2f,av=%.2f",location->x,location->y,location->theta,
                location->linear_velocity,location->linear_velocity);
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 初始化ROS节点
    ros::init(argc,argv,"Location");
    // 实例化ROS句柄
    ros::NodeHandle nh;
    // 实例化订阅者对象
    ros::Subscriber sub=nh.subscribe<turtlesim::Pose>("/turtle1/pose",1000,doMsg);
    // 消息处理函数

    // 回调
    ros::spin();
    return 0;
}
