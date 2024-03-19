/*
    将乌龟一的坐标转换到为乌龟二坐标系中
*/

#include "ros/ros.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 初始化ROS节点
    ros::init(argc,argv,"turtle_transform");
    // 实例化ROS句柄
    ros::NodeHandle nh;
    // 实例化坐标关系订阅者对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    // 实例化位姿发布者对象
    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/solider/cmd_vel",1000);

    ros::Rate r(10);
    while (ros::ok())
    {
        try
        {
        // 将坐标关系进行转换，将换算关系存储到tfs中
        /*
            让乌龟solider可以跟随乌龟turtle1的原理是： tfs不断解算两乌龟间的坐标关系，然后通过twist对乌龟solider的
            cmd_vel话题进行发布，由此来控制乌龟运动，而cmd_vel控制的原理就是通过距离和角度进行移动，当solider越来越
            接近turtle1时，坐标系之间的角度和距离不断减小直至等于0，于是线速度和角速度也逐渐变小，由此达到追踪目的
        */
        geometry_msgs::TransformStamped tfs=buffer.lookupTransform("solider","turtle1",ros::Time(0));
        // 根据坐标关系生成速度关系
        geometry_msgs::Twist twist;
            // twist的linear指的是线速度，x向前走，y横着走，z原地起飞
            // twist的angular指的是角速度，x打滚，y抬头低头，z转向
        twist.linear.x=0.5*sqrt(pow(tfs.transform.translation.x,2)+pow(tfs.transform.translation.y,2));
        twist.angular.z=4*atan2(tfs.transform.translation.y,tfs.transform.translation.x);

        // 发布速度消息
        pub.publish(twist);
        }
        catch(const std::exception& e)
        {
            ROS_INFO("错误提示：%s",e.what());
        }
        
        r.sleep();
        ros::spinOnce();
    }
    
    return 0;
}

