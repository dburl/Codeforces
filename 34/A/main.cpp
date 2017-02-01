#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct S{
	S(int id, int h):id(id),h(h){}
	int id;
	int h;

};
bool compS(S& a, S&b){
	return a.h<b.h;
}
struct P{
	P(int d,int s1, int s2):d(d),s1(s1),s2(s2){}
	int d;
	int s1;
	int s2;
};
bool compP(P& a, P& b){
	return a.d<b.d;
}

int main(){
	int n;
	cin>>n;
	vector<S> v;
	for (int i=0;i<n;++i){
		int tmp;
		cin>>tmp; v.push_back(S(i+1, tmp));
	}
	sort(v.begin(),v.end(),compS);
	vector<P> diff;
	for (int i=0;i<n-1;++i){
		diff.push_back(P(v[i+1].h-v[i].h,v[i+1].id,v[i].id));
		//cout<<diff[i].d<<endl;
		//cout<<diff[i].s1<<" "<<diff[i].s2<<endl;
	}
	diff.push_back(P(v[n-1].h-v[0].h,v[n-1].id,v[0].id));
	//cout<<diff[n].d<<endl;
	//cout<<diff[n].s1<<" "<<diff[n].s2<<endl;
	sort(diff.begin(),diff.end(),compP);
	cout<<diff[0].s1<<" "<<diff[0].s2<<endl;



	return 0;
}
