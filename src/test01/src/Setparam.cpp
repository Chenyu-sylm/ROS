// 参数服务器
    // 参数设置

#include "ros/ros.h"

int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"setparam");

    std::vector<std::string> stus;
    stus.push_back("zhangsang");
    stus.push_back("lisi");
    stus.push_back("chengyu");
    stus.push_back("wangwu");

    std::map<std::string,std::string> friends;
    friends["guo"]="huang";
    friends["yuang"]="xiao";

    ros::NodeHandle nh;
    nh.setParam("nh_int",10);
    nh.setParam("nh_double",3.14);
    nh.setParam("nh_bool",true);
    nh.setParam("nh_string","Hello!");
    nh.setParam("nh_vector",stus);
    nh.setParam("nh_map",friends);

    return 0;
}
