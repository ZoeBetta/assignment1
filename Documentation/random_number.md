# Research Track I - first assignment

# Functions file random_number.cpp

## float randMToN(float M, float N)

Declared in the file random_number.cpp

@brief this function given two inputs calculates one random number in the interval in between. Both the numbers taken as inputs and the random number generated are float. The random number is chosen with the function void rand(), a library function of the C language that generates a pseudo random number. In order to have the random number in a given interval I first multiply the random number generated by RAND_MAX that is a constant that represent the maximum random number generated by rand and then I divide by N-M that gives me a random number in the interval [0;(N-M)]. In order to translate it and have it in the interval [M;N] I sum it to M.
 
@param M is the minimum number of the interval 

@param N is the maximum number of the interval

@retval the random number


## bool myrandom(assignment1::random::Request &req, assignment1::random::Response &res) 

Declared in the file random_number.cpp

@brief this function is called when I have a request, it reads the request and output the coordinates of the target. This function receives as input the server request and a pointer to the server response. The server request are the maximum and minimum of the interval I want to generate the random number in between. When I have a service request it calls the function randMToN that returns a random number, (see randMToN). Once it has both numbers it sends them as response of the server and prints them on the screen.

 *@param final_assignment::random::Request &req the request received from the client: the minimum and maximum of the interval

 *@param final_assignment::random::Response &res the response returned to the client
						 the coordinates randomly chosen in the interval
 */

