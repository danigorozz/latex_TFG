#include "rgbd_filter/cam_info.hpp"

int main(int argc, char** argv){
    
    ros::init(argc, argv, "cam_info");
    
    CamInfo cam_info;
    
    ros::spin();
    
}
