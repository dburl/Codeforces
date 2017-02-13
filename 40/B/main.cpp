#include <iostream>

using namespace std;

int main(){
	long n,m,x;
	cin>>n>>m;
	cin>>x;
	//
	--x;
	long w=m-2*x;
	long h=n-2*x;
	if (w<=0||h<=0){
		cout<<0<<endl;
		return 0;
	}
	long num= w*h-(((w-2)>0&&(h-2)>0)?(w-2)*(h-2):0);
	bool black = false;
	//	cout<<"num:"<<num<<endl;
	cout<<((num%2==0)?num/2:num/2+1)<<endl;

	return 0;
}
