#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;	
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	//
	sort(v.begin(),v.end());
	int totalNum=0;
	vector<int> h;
	h.push_back(1);
	for (int i=1;i<n;++i){
		if (v[i]==v[i-1]){
			h.back()+=1;			
		} else {
			h.push_back(1);
		}
	}
	sort(h.begin(),h.end());
	cout<<h.back()<<" "<<h.size()<<endl;

	return 0;
}
