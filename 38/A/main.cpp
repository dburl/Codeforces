#include <iostream>
#include <vector>
using namespace std;


int main(){
	int  n;
	cin>>n;
	vector<int> d(n);
	for (int i=1;i<(n);++i){
		cin>>d[i];
	}
	int a,b;
	cin>>a>>b;
	//
	int count=0;	
	for (int i=a;i<b;++i){
		count+=d[i];
	}
	cout<<count<<endl;
	return 0;
}
