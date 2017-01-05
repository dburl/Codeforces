#include <iostream>

using namespace std;
int main(){
	double a1,b1, c1, a2, b2, c2;
	cin>> a1>> b1>> c1;
	cin>> a2>> b2>> c2;
	
	if(b1!=0) {
		if (b2!=0){
			if (a1/b1==a2/b2 && c1==c2) {cout<<"-1"<<endl; return 0;}
			else if ((a1/b1==a2/b2 && c1!=c2)) {cout<<"0"<<endl; return 0;}
			else {cout<<"1"<<endl; return 0;}
		} else {
			cout<<"1"<<endl; return 0;
		}
	} else{
		if (b2!=0){
			cout<<"1"<<endl; return 0;
		} else {
		       if (c1/a1==c2/a1) {cout<<"-1"<<endl; return 0;}
			else  {cout<<"0"<<endl; return 0;}
		}
	}
	
	return 0;
}
