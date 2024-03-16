// 服务通信
    // 客户端实现

#include "ros/ros.h"
#include "test01/Add.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");

    // 调用时动态传值
    if (argc!=3)
    {
        ROS_ERROR("请提交两个整数");
        return 1;
    }
    
    // 初始化ROS节点
    ros::init(argc,argv,"client");
    // 实例化ROS句柄
    ros::NodeHandle nh;
    // 创建客户端对象
    ros::ServiceClient client=nh.serviceClient<test01::Add>("Add");
    
    // 等待服务启动成功
    client.waitForExistence();

    // 对请求数据进行组织
        // 创建消息载体
    test01::Add add;
    add.request.num1=atoi(argv[1]);
    add.request.num2=atoi(argv[2]);

    // 发送请求
    bool flag=client.call(add);
    if (flag)
    {
        ROS_INFO("处理正常请求，得到的结果为:%d",add.response.sum);
    }
    else
    {
        ROS_ERROR("请求响应失败");
        return 1;
    }
    
    return 0;
}
