#include <iostream>

using namespace std;

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	//
	int res=(2*m+k*(k-1)+(n-k)*(n-k+1))/(2*n);
	cout<<res<<endl;


	return 0;
}
