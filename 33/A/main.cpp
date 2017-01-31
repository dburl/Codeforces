#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Tooth{
	public:
	int r;
	int c;
};

bool comp(Tooth& a, Tooth& b){
	if (a.r!=b.r){
		return a.r<b.r;
	} else {
		return a.c<b.c;
	}
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<Tooth> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i].r>>v[i].c;
	}
	//
	sort(v.begin(),v.end(),comp);
	int total=0;
	for (int i=0;i<n;++i){
		if (i==0||v[i-1].r!=v[i].r){
			total+=v[i].c;
		}
	}
	cout<<min(total,k)<<endl;
	return 0;
}
