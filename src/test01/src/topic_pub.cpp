// 话题通信---自定义消息格式
    // 循环发布

#include "ros/ros.h"
#include "test01/Person.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");

    // 初始化ROS节点
    ros::init(argc,argv,"Publisher");
    // 实例化ROS句柄
    ros::NodeHandle nh;
    // 实例化发布者对象
        // 泛型是前面引用的头文件Person
    ros::Publisher pub=nh.advertise<test01::Person>("chatter",100);
    // 组织发布消息内容
    test01::Person person;
    person.age=19;
    person.height=178;
    person.name="ChenYu";
    // 编写发布逻辑
    ros::Rate r(1);
    while (ros::ok())
    {
        pub.publish(person);
        person.age+=1;
        ROS_INFO("我叫%s,今年%d岁,身高%.2f厘米",person.name.c_str(),person.age,person.height);

        r.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
