#include <ros/ros.h>

#include <string>
#include <iostream>
#include <fstream>

#include <sensor_msgs/Image.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <darknet_ros_msgs/BoundingBoxes.h>
#include <darknet_ros_msgs/BoundingBox.h>

using namespace sensor_msgs;
using namespace darknet_ros_msgs;

class WriteObjects{
    
public:
    
    WriteObjects();
    
    void cb_bboxes(const BoundingBoxes::ConstPtr& msg);
    void cb_pose(const geometry_msgs::PoseWithCovarianceStampedConstPtr & msg);
    
    
    
    
private:
    
    ros::NodeHandle nh;
    ros::Subscriber sub_bboxes;
    ros::Subscriber sub_pose;
    
    std::string position;
    std::string orientation;
    
    std::string str_objetos;
    std::string str_probs;
    
    double start_time;
    
    
};
