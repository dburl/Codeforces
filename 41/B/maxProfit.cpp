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
	long bL=b;
	long dL=0;
	vector<long> bT;
	bT.push_back(bL);
	for (int i=0;i<(n-1);++i){
		if (v[i+1]>v[i]){
			dL+=bL/v[i];
			bL=bL%v[i];
		} else if (v[i+1]<v[i]){
			bL+=v[i]*dL;
			dL=0;
		}
		bT.push_back(bL+v[i]*dL);
	}	
	bT.push_back(bL+v.back()*dL);
	sort(bT.begin(),bT.end());
	cout<<bT.back()<<endl;
	return 0;
}
