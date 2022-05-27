#!/usr/bin/env python

import rospy
import message_filters
from sensor_msgs.msg import Image, CameraInfo

class SyncInfo:

    def __init__(self):
        
        self.depth_topic = "camera_down/depth/image"
        self.info_topic = "camera_info"
        
        self.pub_depth = rospy.Publisher('sync/depth_image', Image, queue_size=10)
        self.pub_info = rospy.Publisher('sync/camera_info', CameraInfo, queue_size=10)

        sub_depth = message_filters.Subscriber(self.depth_topic, Image) 
        sub_info = message_filters.Subscriber(self.info_topic, CameraInfo) 

        message_filter = message_filters.ApproximateTimeSynchronizer([sub_depth, sub_info], 10, 0.5) 
        message_filter.registerCallback(self.callback) 
            

    def callback(self, depth_msg, info_msg): 

        self.pub_depth.publish(depth_msg)
        self.pub_info.publish(info_msg)


if __name__ == '__main__':
    rospy.init_node('sync_info', anonymous=True)
    myNode = SyncInfo()
    rospy.spin()
