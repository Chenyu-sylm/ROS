/*
    订阅坐标系信息
    生成一个相对于子级坐标系的坐标点数据，转换成父级坐标系中的坐标点
*/

#include "ros/ros.h"
    // 用于缓存接收到的坐标点信息
#include "tf2_ros/buffer.h"
    // 用于创建订阅者对象
#include "tf2_ros/transform_listener.h"
    // 用于生成点坐标消息包
#include "geometry_msgs/PointStamped.h"
    // 用于生成tf2格式的包含坐标信息的消息包,调用transform必须调用此文件
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 初始化ROS节点
    ros::init(argc,argv,"Listener");
    // 创建缓存对象
    tf2_ros::Buffer buffer;
    // 创建订阅者对象
    tf2_ros::TransformListener listener(buffer);


    ros::Rate r(1);
    while (ros::ok())
    {
        // 生成一个子级坐标系中的坐标点
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id="laser";
        point_laser.header.stamp=ros::Time::now();
        point_laser.point.x=1;
        point_laser.point.y=2;
        point_laser.point.z=7.3;

        // 利用坐标关系进行转换坐标点
        try
        {
            // 新建一个坐标点用于接收转换结果
            geometry_msgs::PointStamped point_base;
            // 在缓存中对坐标进行转换，得出目标坐标点
            point_base=buffer.transform(point_laser,"base_link");
            ROS_INFO("转换后的坐标为:%.2f,%.2f,%.2f,参考坐标系为:%s ",point_base.point.x,point_base.point.y,point_base.point.z,point_base.header.frame_id.c_str());
        }
        catch(const std::exception& e)
        {
            ROS_WARN("程序异常....");
        }
        r.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
