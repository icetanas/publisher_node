//roscpp Core header 
#include "ros/ros.h"
//Header of Int32 standard message
#include "std_msgs/Int32.h"
#include <iostream>


int main(int argc, char **argv)

{

	//Initializing ROS node with a name of publisher_node
	ros::init(argc, argv,"publisher_node");

	//Created a node handle object
	ros::NodeHandle node_obj;

	//Created a publisher object
	ros::Publisher number_publisher = node_obj.advertise<std_msgs::Int32>("/motor_speed",10);

	//Created a rate object
	ros::Rate loop_rate(100);

	//Variable of the number initializing as zero
	int number_count = 0;

	//While loop for incrementing number and publishing to topic /numbers
	while (ros::ok())
	{

		//Created a Int32 message
		std_msgs::Int32 msg;

		//Inserted data to message header
		msg.data = number_count;

		//Printing message data
		// ROS_INFO("%d",msg.data);

		//Publishing the topic 
		number_publisher.publish(msg);

		//Spinning once for doing the  all operation once
		ros::spinOnce();

		//Sleeping for sometime
		loop_rate.sleep();

		//Incrementing the count
		++number_count;
		if(number_count>1023){number_count=0;}
	}
	
	return 0;
}


