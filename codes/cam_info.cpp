#include "rgbd_filter/cam_info.hpp"

CamInfo::CamInfo(){
    
    sub = nh.subscribe("camera_down/depth/image", 1000, &CamInfo::callback, this);
    pub = nh.advertise<sensor_msgs::CameraInfo>("camera_info",1000);
    
}

void CamInfo::callback(const sensor_msgs::Image::ConstPtr& msg){
    
    sensor_msgs::CameraInfo cam_msg;
    
    cam_msg.header = msg->header;
    cam_msg.height = msg->height;
    cam_msg.width = msg->width;
    cam_msg.distortion_model = "plumb_bob";
    cam_msg.D = {0.0, 0.0, 0.0, 0.0, 0.0};
    cam_msg.K = {579.385009765625, 0.0, 318.2640075683594, 0.0, 579.385009765625, 234.93800354003906, 0.0, 0.0, 1.0};
    cam_msg.R = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
    cam_msg.P = {579.385009765625, 0.0, 318.2640075683594, 0.0, 0.0, 579.385009765625, 234.93800354003906, 0.0, 0.0, 0.0, 1.0, 0.0};
    cam_msg.binning_x = 0;
    cam_msg.binning_y = 0;
    cam_msg.roi.do_rectify = false;
    cam_msg.roi.x_offset = 0;
    cam_msg.roi.y_offset = 0;
    cam_msg.roi.height = 0;
    cam_msg.roi.width = 0;
    
    pub.publish(cam_msg);
    
}
