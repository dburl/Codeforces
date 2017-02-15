#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int n,b;
	cin>>n>>b;
	vector<int> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	//
	long m=b;
	for (int i=v.size()-2; i>=0; --i){
		sort(v.begin()+i+1,v.end());
		long t=	b%v[i]+	(b/v[i])*v.back();
		m=(t>m)?t:m;
	}
	cout<<m<<endl;
	return 0;
}
