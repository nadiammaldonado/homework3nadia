#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "untitled_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block untitled/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_untitled_std_msgs_Float64> Sub_untitled_16;

// For Block untitled/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_untitled_std_msgs_Float64> Sub_untitled_17;

// For Block untitled/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_untitled_std_msgs_Float64> Pub_untitled_11;

// For Block untitled/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_untitled_std_msgs_Float64> Pub_untitled_12;

void slros_node_init(int argc, char** argv);

#endif
