// 参数服务器
    // 参数获取

#include "ros/ros.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"getparam");
    ros::NodeHandle nh;

    int nh_int_value;
    double nh_double_value;
    bool nh_bool_value;
    std::string nh_string_value;
    std::vector<std::string> stus;
    std::map<std::string,std::string> friends;

    nh.getParam("nh_int",nh_int_value);
    nh.getParam("nh_double",nh_double_value);
    nh.getParam("nh_bool",nh_bool_value);
    nh.getParam("nh_string",nh_string_value);
    nh.getParam("nh_vector",stus);

    ROS_INFO("获取的结果: %d,%.2f,%s,%d",nh_int_value,nh_double_value,nh_string_value.c_str(),nh_bool_value);
    for ( auto stu:stus)
    {
        ROS_INFO("stus元素:%s",stu.c_str());
    }
    
    return 0;
}
