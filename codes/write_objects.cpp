#include "rgbd_filter/write_objects.hpp"

using namespace sensor_msgs;
using namespace darknet_ros_msgs;

WriteObjects::WriteObjects(){
    
    sub_bboxes = nh.subscribe("/darknet_ros/bounding_boxes", 1, &WriteObjects::cb_bboxes, this);
    sub_pose = nh.subscribe("/amcl_pose", 1, &WriteObjects::cb_pose, this);
    
    position = "";
    orientation = "";
    str_objetos = "";
    str_probs = "";
    
    start_time = ros::Time::now().toSec();
    
}


void WriteObjects::cb_bboxes(const BoundingBoxes::ConstPtr& msg){
    
    std::vector<BoundingBox> v = msg->bounding_boxes;
    int n = v.size();
    
    str_objetos = "";
    str_probs = "";
    
    // Si hay objetos detectados ->
    if(n != 0){
        
        // Iteramos en cada uno de los objetos y lo anadimos a un array junto con su probabilidad
        for(int i=0; i<n; i++){
            str_objetos.append(v[i].Class);
            str_objetos.append(":");
            str_probs.append(std::to_string(v[i].probability));
            str_probs.append(":");
        }
        
        // Eliminamos la ultima ","
        str_objetos = str_objetos.substr(0, str_objetos.size()-1);
        str_probs = str_probs.substr(0, str_probs.size()-1);

        // Obtenemos el tiempo de simulacion
        double time = ros::Time::now().toSec() - start_time;
        
        // Escribimos en el archivo
        std::ofstream myfile;
        myfile.open("/home/daniel/Documentos/objetos.txt", std::ios::ate | std::ios::app);
        myfile << str_objetos << ";" << str_probs << ";" << position << ";" << orientation << ";" << std::to_string(time) << "\n";
        myfile.close();
        
    }
        
}

void WriteObjects::cb_pose(const geometry_msgs::PoseWithCovarianceStampedConstPtr & msg){
    
    geometry_msgs::Point position_ = msg->pose.pose.position;
    geometry_msgs::Quaternion orientation_ = msg->pose.pose.orientation;
    
    std::string pos_x = std::to_string(position_.x); 
    std::string pos_y = std::to_string(position_.y); 
    std::string pos_z = std::to_string(position_.z);
    
    std::string or_w = std::to_string(orientation_.w);
    std::string or_x = std::to_string(orientation_.x);
    std::string or_y = std::to_string(orientation_.y);
    std::string or_z = std::to_string(orientation_.z);
    
    position = pos_x + ':' + pos_y + ':' + pos_z;
    orientation = or_w + ':' + or_x + ':' + or_y + ':' + or_z;
    
}










