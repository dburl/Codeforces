#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
 
int main(){
	// input
	unsigned long n, m, a;
	while(std::cin>>n>>m>>a){
		// how many fit 
		const unsigned long long vertNum = (n%a)?n/a+1:n/a;
		const unsigned long long horizNum= (m%a)?m/a+1:m/a;
		// result
		std::cout<< vertNum*horizNum<< std::endl;
	}
	return 0;
}
