#include <iostream>

using namespace std;

int main(){
	int n,m,s;
	cin>>n>>m>>s;
	//
	int mHorJumps=max(1, (n-1)/s+1);
	int mVerJumps=max(1, (m-1)/s+1);
	int horSlack=(n-1)%s+1;
	int verSlack=(m-1)%s+1;

	long long hCombin=horSlack*mHorJumps;
	long long vCombin=verSlack*mVerJumps;

	long long res= hCombin*vCombin;

	cout<<res<<endl;


	return 0;
}
