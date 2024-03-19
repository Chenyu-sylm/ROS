/*
    第一步   先在指定位置生成乌龟
    服务话题   /spawn
    服务消息格式   turtlesim/Spawn
    服务消息内容   
    float32 x
    float32 y
    float32 theta
    string name
    ---
    string name
*/

#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char  *argv[])
{
    // 初始化节点
    ros::init(argc,argv,"spawn_turtle");
    // 实例化句柄
    ros::NodeHandle nh;
    // 实例化客户端对象
    ros::ServiceClient client=nh.serviceClient<turtlesim::Spawn>("/spawn");
    // 等待请求响应成功
    client.waitForExistence();
    // 组织请求消息内容
    turtlesim::Spawn spawn;
    spawn.request.name="solider";
    spawn.request.theta=0.3;
    spawn.request.x=5.4;
    spawn.request.y=1.2;
    // 发送消息
    client.call(spawn);
    return 0;
}
