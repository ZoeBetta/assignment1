/* author: Zoe Betta
 * Date of creation 19/11/2020
 * 
 * ASSIGNMENT 1
 * Research track 1
 *
 * server that calculates 2 random numbers between two inputs
*/

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "assignment1/random.h"

// function declaration
float randMToN(float M, float N);
bool myrandom(assignment1::random::Request &req, assignment1::random::Response &res);

//main function
int main(int argc, char **argv)
{	// initialization of the server
 	ros::init(argc, argv, "random_number");
 	ros::NodeHandle n1;
 	ros::ServiceServer service=n1.advertiseService("/random", myrandom); 
 	ros::spin();

 	return 0;

}

/**
 *@brief this function given two inputs calculates one random number in the interval in between
 *@param M is the minimum number of the interval 
 *@param N is the maximum number of the interval
 *@retval the random number
 */
float randMToN(float M, float N)
{
	return M+(rand() / (RAND_MAX / (N-M) ) ) ;
}

/**
 *@brief this function is called when I have a request, it reads the request and output the coordinatesof the target
 *@param final_assignment::random::Request &req the request received from the client
						the minimum and maximum of the interval
 *@param final_assignment::random::Response &res the response returned to the client
						 the coordinates randomly chosen in the interval
 */
bool myrandom(assignment1::random::Request &req, assignment1::random::Response &res)
{
	res.a=randMToN(req.min, req.max);
	res.b=randMToN(req.min, req.max);
	ROS_INFO("Random Target [%f, %f]", res.a, res.b);
	return true;
}

