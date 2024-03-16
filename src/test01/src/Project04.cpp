// 通过参数服务器设置乌龟背景颜色    注意命名空间的使用
/*
    获取参数名称
    /turtlesim/background_b
    /turtlesim/background_g
    /turtlesim/background_r
*/

#include "ros/ros.h"

int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"Setcolor");
    ros::NodeHandle nh;
    ros::param::set("/turtlesim/background_r",0);
    ros::param::set("/turtlesim/background_g",0);
    ros::param::set("/turtlesim/background_b",0);

    /*
    ros::NodeHandle nh("turtlesim");
    nh.setParam("background_r",0);
    nh.setParam("background_g",0);
    nh.setParam("background_b",0);
    */

    return 0;
}
