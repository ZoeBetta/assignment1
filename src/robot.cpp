/* author: Zoe Betta
 * Date of creation 19/11/2020
 * 
 * ASSIGNMENT 1
 * Research track 1
 * Node that implements the robot behaviour
 *
*/

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"
#include "assignment1/random.h"

// definitios of global variables: the publisher, the server client, the Target message, the current position of the robot and the distances 
	using namespace nav_msgs;
	ros::Publisher chatter_pub;
	ros::ServiceClient client;
	nav_msgs::Odometry Target;
	nav_msgs::Odometry Position;
	geometry_msgs::Twist msg;
	float distanceX=0;
	float distanceY=0;
	int k=2;

//function declaration
void chatterCallback( const Odometry:: Ptr& x);

//main function
int main(int argc, char **argv)
{	// inizializaion of service client, publisher for the velocity of the robot and subscriber for the current position of the robot
	ros::init(argc, argv, "robot");
	ros:: NodeHandle n2;
	ros:: NodeHandle n3;
	ros:: NodeHandle n4;
	client= n2.serviceClient<assignment1::random>("random");
	chatter_pub= n3.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
	ros:: Subscriber robot_position= n4.subscribe("odom", 1000, chatterCallback);

	ros:: spin();
	return 0;
}

/**
 *@brief this function is called everytime something is read on the topic /odom and decides if the robot should ask for a new position or publishes a new velocity
 *@param x it is a variable of type Odometry that has informations about the position of the robot 
 *@retval none
 */
void chatterCallback( const Odometry:: Ptr& x)
{ 
	// every time I call the callback of the subscriber I read the current position of the robot
	Position.pose.pose.position.x=x->pose.pose.position.x;
	Position.pose.pose.position.y=x->pose.pose.position.y;
	// I compute the distance from the Target point
	distanceX=Target.pose.pose.position.x-Position.pose.pose.position.x;
	distanceY=Target.pose.pose.position.y-Position.pose.pose.position.y;
	// I check if the distances along x and along y are both in the interval -0.1 and 0.1
	// if that's the case I ask the server for another Target point
	// if that's not the case I publish the velocity of the robot proportional to the distance
	if((distanceX>=-0.1 && distanceX<=0.1) && (distanceY>=-0.1 && distanceY<=0.1))
		{	
			assignment1::random srv;
			srv.request.min= -6;
			srv.request.max= 6;
			client.call(srv);
			Target.pose.pose.position.x=srv.response.a;
			Target.pose.pose.position.y=srv.response.b;
		}

	else
		{	
			msg.linear.x=k*distanceX;
			msg.linear.y=k*distanceY; 
			chatter_pub.publish(msg);
		}
}
