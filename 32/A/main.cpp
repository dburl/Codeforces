#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,d;
	cin>> n>>d;
	vector<int> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	//
	sort(v.begin(),v.end());
	//for (int i=0;i<n;++i){
	//	cout<<v[i]<<endl;
	//}
	int l=0, r=0;
	long comb=0;
	for (int i=0;i<n;++i){
		while (r+1<v.size() && (v[r+1]-v[i])<=d ){
			++r;
		}
		while (v[i]-v[l]>d){++l;}
		comb+=r-l;
	}
	cout<<comb<<endl;
	




	return 0;
}
