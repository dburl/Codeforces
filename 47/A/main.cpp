#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	//
	for (int i=0;i<sqrt(2*n);++i){
		if (2*n==(i*(i+1))){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;

	return 0;
}
