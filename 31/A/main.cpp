#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	int n;
	cin>> n;
	vector<int> v(n);
	map<int,int> m;
	for(int i=0;i<n;++i){
		cin>>v[i];
		m[v[i]]=i+1;		
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			if (j==i) continue;
			for (int k=0;k<n;++k){
				if ((k==j) || (k==i)) continue;
				if (v[i]==(v[k]+v[j])){
					cout<< i+1<<" "<<k+1<< " "<<j+1<<endl;
					return 0;			
				}
			}
		}
	}
	
	cout<<"-1"<<endl;
	return 0;
}
