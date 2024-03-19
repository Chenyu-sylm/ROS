/*
    第三步   获取乌龟二在世界坐标系中的坐标
*/

#include "ros/ros.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "turtlesim/Pose.h"
#include "tf2/LinearMath/Quaternion.h"

// 回调函数实现和处理
void doPose(const turtlesim::Pose::ConstPtr& pose)
{
    // 创建广播对象
   static  tf2_ros::TransformBroadcaster broadcaster;
    // 创建tf消息载体
    geometry_msgs::TransformStamped tfs;
        // 头设置
    tfs.header.frame_id="world";
    tfs.header.stamp=ros::Time::now();
        // ID设置
    tfs.child_frame_id="solider";
        // 相对消息设置
    tfs.transform.translation.x=pose->x;
    tfs.transform.translation.y=pose->y;
    tfs.transform.translation.z=0.0;
        // 四元数设置
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    tfs.transform.rotation.x=qtn.getX();
    tfs.transform.rotation.y=qtn.getY();
    tfs.transform.rotation.z=qtn.getZ();
    tfs.transform.rotation.w=qtn.getW();

    // 广播器发布数据
    broadcaster.sendTransform(tfs);

}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 初始化ROS节点
    ros::init(argc,argv,"broadcast2");
    // 实例化ROS句柄
    ros::NodeHandle nh;
    // 创建订阅者对象
    ros::Subscriber sub=nh.subscribe<turtlesim::Pose>("/solider/pose",1000,doPose);
    // 回调函数实现和处理
    
    ros::spin();

    return 0;
}



