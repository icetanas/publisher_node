//roscpp Core header 
#include "ros/ros.h"
//Header of Int32 standard message
#include "std_msgs/Int16.h"
#include <iostream>


int main(int argc, char **argv)

{

	//Initializing ROS node with a name of publisher_node
	ros::init(argc, argv,"publisher_motor_value_node");

	//Created a node handle object
	ros::NodeHandle node_obj;

	//Created a publisher object
	ros::Publisher wheel_left = node_obj.advertise<std_msgs::Int16>("/wheel_left_speed",10);
	ros::Publisher wheel_right = node_obj.advertise<std_msgs::Int16>("/wheel_right_speed",10);

	//Created a rate object
	ros::Rate loop_rate(1000);

	//Variable of the number initializing as zero
	int wheel_left_count = 0;
	int wheel_right_count = 0;

	//While loop for incrementing number and publishing to topic /numbers
	while (ros::ok())
	{

		//Created a Int32 message
		std_msgs::Int16 msg_wheel_left;
		std_msgs::Int16 msg_wheel_right;

		//Inserted data to message header
		msg_wheel_left.data = wheel_left_count;
		msg_wheel_right.data = wheel_right_count;

		//Printing message data
		// ROS_INFO("%d",msg.data);

		//Publishing the topic 
		wheel_left.publish(msg_wheel_left);
		wheel_right.publish(msg_wheel_right);

		//Spinning once for doing the  all operation once
		ros::spinOnce();

		//Sleeping for sometime
		loop_rate.sleep();

		//Incrementing the count
		wheel_left_count++;
		wheel_right_count += 2;
		if(wheel_left_count>1023){wheel_left_count=0;}
		if(wheel_right_count>1023){wheel_right_count=0;}
	}
	
	return 0;
}


