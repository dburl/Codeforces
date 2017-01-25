#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
	int a,b,n;
	cin>>a>>b>>n;
	if (a==0 && b!=0){cout<<"No solution"<<endl;return 0;}
	if (a==0 && b==0){cout<<"0"<<endl;return 0;}
	int r=b/a;
	if ((r<0) && (n%2==0)){cout<<"No solution"<<endl;return 0;}
	bool neg= (r<0);
	r=abs(r);
	for (int x=0;x<=r;++x){
		int acc=x;
		for(int j=1;j<n;j++){
			acc=acc*x;
		}
		if (acc==r && (a*((neg)?-1:1)*acc==b)){
			cout<<((neg)?"-":"")<<x<<endl;
			return 0;
		}
		
	}
	cout<<"No solution"<<endl;
	return 0;
}