// 服务通信
    // 服务端实现

#include "ros/ros.h"
#include "test01/Add.h"

// 服务实现函数，参数为srv消息文件内向量指针的引用
bool doReq(test01::Add::Request& req,test01::Add::Response& resp)
{
    int num1=req.num1;
    int num2=req.num2;

    ROS_INFO("请求数据为:num1=%d, num2=%d",num1,num2);

    if (num1<0 || num2<0)
    {
        ROS_ERROR("数据异常");
        return false;
    }
    resp.sum=num1+num2;
    return true;

}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 初始化ROS节点
    ros::init(argc,argv,"server");
    // 实例化ROS句柄
    ros::NodeHandle nh;
    // 创建服务端对象
        // 设置服务话题 和 服务内容函数
    ros::ServiceServer server=nh.advertiseService("Add",doReq);

    ROS_INFO("服务端启动...");
    // 回调函数处理请求并响应
    ros::spin();
    return 0;
}
