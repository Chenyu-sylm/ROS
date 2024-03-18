/*
    将乌龟坐标点相对于世界坐标点的坐标进行转换后输出
    倾听者---利用广播的转换关系转换后输出
*/

#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 初始化ROS节点
    ros::init(argc,argv,"listener");
    ros::NodeHandle nh;
    // 实例化listener对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Rate r(1);

    while (ros::ok())
    {
        // 生成坐标点
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id="turtle1";
        point_laser.header.stamp=ros::Time();

        point_laser.point.x=1;
        point_laser.point.y=1;
        point_laser.point.z=0;

        // 进行转换坐标点
        try
        {
            // 转换后存储坐标点
            geometry_msgs::PointStamped point_base;
            point_base=buffer.transform(point_laser,"world");

            ROS_INFO("相对于world坐标为:%.2f,%.2f,%.2f",point_base.point.x,point_base.point.y,point_base.point.z);

        }
        catch(const std::exception& e)
        {
            ROS_WARN("程序异常:%s",e.what());
        }
    r.sleep();
    ros::spinOnce();
    }
    return 0;
}
