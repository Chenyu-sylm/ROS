/*
    静态消息发布方：发布关于laser坐标系的位置信息
*/

#include "ros/ros.h"
    // 用于创建发布者对象
#include "tf2_ros/static_transform_broadcaster.h"
    // 用于生成转换关系的消息包
#include "geometry_msgs/TransformStamped.h"
    // 四元数转换
#include "tf2/LinearMath/Quaternion.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 创建ros节点
    ros::init(argc,argv,"static_brocast");
    // 创建坐标信息广播器
    tf2_ros::StaticTransformBroadcaster broadcaster;
    // 组织坐标信息内容
    geometry_msgs::TransformStamped ts;
        // 设置头信息
    ts.header.seq=100;
    ts.header.stamp=ros::Time::now();
    ts.header.frame_id="base_link";
        // 设置子级坐标系
    ts.child_frame_id="laser";
        // 设置偏移量
    ts.transform.translation.x=0.2;
    ts.transform.translation.y=0.0;
    ts.transform.translation.z=0.5;
        // 设置四元数
        // 将欧拉角转换成四元数
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,0);
    ts.transform.rotation.x=qtn.getX();
    ts.transform.rotation.y=qtn.getY();
    ts.transform.rotation.z=qtn.getZ();
    ts.transform.rotation.w=qtn.getW();
    // 将转换坐标系消息内容发布出去
    broadcaster.sendTransform(ts);
    ros::spin();
    return 0;
}
