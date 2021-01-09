# Research Track I - first assignment

# Functions file robot.cpp

## void chatterCallback( const Odometry:: Ptr& x)

declared in robot.cpp

@brief this function is called everytime something is read on the topic /odom, it calculates the distance between the current position of the robot and the target. If the distance is less than a given threshold, in this case in absolute value less than 0.1 for both the x and y coordinates, it asks for a new target. On the other hand if it the distance is greater than 0.1 I set the linear velocities along x and y proportional to the distance and I publish them on the topic cmd_vel.

@param x it is a variable of type Odometry that has informations about the position of the robot
 
@retval none




