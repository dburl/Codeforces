#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	float x, y;
	cin>>x>>y;
	//
	float r=sqrt(x*x+y*y);
	int rI=(int)r;
	//cout<<rI<<endl;
	if (rI*rI==(x*x+y*y)){
		cout<<"A"<<endl;
		cout<<"black"<<endl;
	} else if (x*y>0){
	//	cout<<"B"<<endl;
		if (rI%2!=0){
			cout<<"white"<<endl;
		} else {
			cout<<"black"<<endl;
		}
	} else {
	//	cout<< "C"<<endl;
		if (rI%2==0){
			cout<<"white"<<endl;
		} else {
			cout<< "black"<<endl;
		}
	}
	return 0;
}
