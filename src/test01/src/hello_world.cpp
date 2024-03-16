// 可执行文件编写
    // 引用头文件中的框架和源文件的具体实现进行功能配置
#include "ros/ros.h"
#include "test01/hello_world.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"headfile");

    hello_world_ns::HelloPub hellopub;
    hellopub.run();
    return 0;
}
