#include "rgbd_filter/write_objects.hpp"

int main(int argc, char** argv){
    
    ros::init(argc, argv, "write_objects");
    
    WriteObjects write_objects;
    
    ros::spin();
    
}
