#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N,K,C;
	cin>>N>>K;
	cin>>C;
	vector<int> v(C+1);
	v[0]=0;
	for (int i=1;i<C+1;++i){
		cin>>v[i];
	}
	v.push_back(N+1);
	vector<int> pv;
	for (int i=1;i<C+2;++i){
		pv.push_back(v[i]-v[i-1]-1);
	}
	sort(pv.begin(),pv.end());
	int acc=0;
	for (int i=pv.size()-1;i>=0;--i){
		acc+=pv[i]/K;
		if ((pv[i]/K)<=0) break;
	}
	cout<<acc+C<<endl;
	return 0;	
}
