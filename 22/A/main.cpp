#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b){return a<b;}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	sort(v.begin(),v.end(), comp);
	for (int i=0;i<n;++i){
		if(v[i]>v[0]){
			cout<<v[i]<<endl;
			return 0;		
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
