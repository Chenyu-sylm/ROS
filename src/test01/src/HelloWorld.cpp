////// Hello world 输出 //////
#include "ros/ros.h"

int main(int argc, char  *argv[])
{
    ///// 中文显示
    setlocale(LC_ALL,"");
    ///// ros初始化创建节点，给节点命名
    ros::init(argc,argv,"Hello");
    //// ros初始化创建句柄
    ros::NodeHandle nh;
    //// 输出文字
    ROS_INFO("Hello World!!");
    return 0;
}
