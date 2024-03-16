// 话题通信---自定义消息格式
    // 循环发布

#include "ros/ros.h"
#include "test01/Person.h"

// 回调函数编写
void Person_msg(const test01::Person::ConstPtr& person_p)
{
    ROS_INFO("人物信息：%s ,%d ,%.2f",person_p->name.c_str(),person_p->age,person_p->height);
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 初始化ROS节点
    ros::init(argc,argv,"subscriber");
    // 实例化ROS句柄
    ros::NodeHandle nh;
    // 实例化订阅者对象
    ros::Subscriber sub=nh.subscribe<test01::Person>("chatter",100,Person_msg);

    ros::spin();
    return 0;
}
