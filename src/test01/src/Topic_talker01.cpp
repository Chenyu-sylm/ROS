//// 话题通信 //////
// 发布方实现

#include "ros/ros.h"
// 发布消息文本，需要引用消息类型头文件
#include "std_msgs/String.h"
// 用于拼接字符串
#include <sstream>

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");

    // 1.初始化ROS节点,发布者节点
    ros::init(argc,argv,"Talker");
    // 2.实例化ROS句柄,句柄中封装了一些常用功能
    ros::NodeHandle nh;
    // 3.实例化 发布者 对象
        // 类型是ros中的Publisher类，创建一个对象； 句柄类的成员advertise用于发布话题功能
        // 泛型：发布的消息类型  参数1：发布的话题 参数2：队列中保存的最大消息数
    ros::Publisher pub=nh.advertise<std_msgs::String>("chatter",10);
    // 4.组织被发布的数据，并编写发布逻辑
        // ROS中用于发布的消息对象，类型是std_msgs
        std_msgs::String msg;
        // 消息对象内容--前缀部分,类型是std
        std::string msg_front="Hello 你好！";
        // 消息计数器
        int count=0;

        // 逻辑：一秒十次
        ros::Rate r(10);

        while (ros::ok())
        {
            // 用stringstream拼接字符串和编号
            std::stringstream ss;
            ss<<msg_front<<count;
            // 组织被发布的消息的内容
            msg.data=ss.str();
            // 发布消息
            pub.publish(msg);
            ROS_INFO("发送的消息：%s",msg.data.c_str());

            // 自动休眠 休眠时间=1/频率
            r.sleep();
            count++;
        }
        
    return 0;
}
