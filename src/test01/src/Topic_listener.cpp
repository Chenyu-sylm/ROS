//// 话题通信 //////
// 订阅方实现

#include "ros/ros.h"
#include "std_msgs/String.h"

// 4.回调函数实现
    // 传入参数是接收的消息，类型为std_msgs::String,采用指针引用的形式指向消息，别名为msg_p
void doMsg(const std_msgs::String::ConstPtr& msg_p)
{
    ROS_INFO("我听见：%s",msg_p->data.c_str());
}


int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 1.初始化ros节点
    ros::init(argc,argv,"Listener");
    // 2.实例化ros句柄
    ros::NodeHandle nh;
    // 3.实例化订阅者对象
        // 订阅者对象类型是ros的subscriber类
        // 泛型：接收的消息类型 利用句柄的subscribe功能进行接受
        // 参数1是订阅的话题 参数2是消息最大队列数 参数3是回调函数，对接收的信息进行处理
    ros::Subscriber sub=nh.subscribe<std_msgs::String>("chatter",10,doMsg);

    // 5.设置循环调用回调函数
        // 循环读取接收的数据，并调用回调函数
    ros::spin();
    
    return 0;
}
