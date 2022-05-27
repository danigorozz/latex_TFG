#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"

class CamInfo{
    
public:
    
    CamInfo();
    
    void callback(const sensor_msgs::Image::ConstPtr & msg);
    
private:
    
    ros::NodeHandle nh;
    ros::Publisher pub;
    ros::Subscriber sub;
    
};
