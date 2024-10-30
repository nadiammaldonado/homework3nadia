#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "untitled";

// For Block untitled/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_untitled_std_msgs_Float64> Sub_untitled_16;

// For Block untitled/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_untitled_std_msgs_Float64> Sub_untitled_17;

// For Block untitled/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_untitled_std_msgs_Float64> Pub_untitled_11;

// For Block untitled/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_untitled_std_msgs_Float64> Pub_untitled_12;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

