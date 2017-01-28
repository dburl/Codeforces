#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int l, d, v , g, r;
	cin >>l>>d>>v>>g>>r;
	//
	double abTime=(double)l/(double)v;
	
	double rest= d%(v*(g+r));
	rest=rest/(double)v;
	double cross=0;
	if (rest>=g){
		cross=g+r-rest;
	} 	
	cout<<setprecision(8)<<abTime+cross<<endl;


	return 0;
}
