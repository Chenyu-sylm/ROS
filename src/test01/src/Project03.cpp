// 在指定位置生成乌龟
/*
    服务类型 /spawn 
    服务消息类型 turtlesim/Spawn
    服务消息内容
    float32 x
    float32 y
    float32 theta
    string name
    ---
    string name

*/

// 引用头文件
#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 初始化ROS节点
    ros::init(argc,argv,"set_turtle");
    // 实例化ROS句柄
    ros::NodeHandle nh;
    // 实例化客户端对象
    ros::ServiceClient client=nh.serviceClient<turtlesim::Spawn>("/spawn");
    // 等待服务启动
    client.waitForExistence();

    // 组织请求
    turtlesim::Spawn spawn;
    spawn.request.name="ChenYu";
    spawn.request.theta=1.57;
    spawn.request.x=1.0;
    spawn.request.y=1.0;

    // 发送请求
    bool flag= client.call(spawn);
    if (flag)
    {
        ROS_INFO("乌龟生成!名字:%s",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("乌龟生成失败!!");
    }
    return 0;
}
