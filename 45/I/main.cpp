#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b){return a>b;}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	//
	sort(v.begin(),v.end(),comp);
	int neg=0;
	int fstNeg=-1;
	for (int i=0;i<n;++i){
		neg+=((v[i]<0)?1:0);
		if (fstNeg<0 && v[i]<0){ fstNeg=i;}
	}
	sort(v.begin()+(fstNeg), v.end());
	vector<int> need;
	neg=neg%2;
	for (int i=0;i<(n-neg);++i){
		if(v[i]!=0){
			need.push_back(v[i]);
		}
	}
	if (need.empty()){need.push_back(v.front());}
		
	for (int i=0;i<need.size();++i){
		cout<<need[i]<<" ";
	}
	cout<<endl;
	return 0;
}
