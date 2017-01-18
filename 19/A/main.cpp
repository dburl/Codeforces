#include<iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Team{
	string name;
	int points;
	int missed;
	int scored;
	long long gl;
};



bool glComp(Team a, Team b){return a.gl>b.gl;}

int main(){
	int n;
	cin>>n;
	map<char,Team> m;
	for (int i=0;i<n;++i){
		char tmp;
		cin>>tmp;
		m[tmp];
		m[tmp].name=tmp;
		m[tmp].points=0;
		m[tmp].scored=0;
		m[tmp].missed=0;
		m[tmp].gl=0;
	}
	//
	for (int i=0;i<(n*(n-1))/2;++i){
		char a,b, tmp;
		int l,r;
		cin>>a>>tmp>>b>>l>>tmp>>r;
		//cout<<a<<endl;
		//cout<<b<<endl;
		//cout<<l<<endl;
		//cout<<r<<endl;
		if (l>r){m[a].points+=3;}
		if (l<r){m[b].points+=3;}
		if (l==r){m[a].points+=1;m[b].points+=1;}
		m[a].scored+=l;		m[b].scored+=r;
		m[a].missed+=r;		m[b].missed+=l;
	}
	vector<Team> v(n);
	int count=0;
	for (map<char,Team>::const_iterator it=m.begin();it!=m.end();++it){
		v[count]=it->second;count++;

	}
	for (int i=0;i<n;++i){
		v[i].gl=((n*(n-1))/2)*((n*(n-1))/2)*v[i].points+(n*(n-1))/2*(v[i].scored-v[i].missed)+(n*(n-1))/2*100-v[i].points ; 
	}
	sort(v.begin(),v.end(),glComp);
	vector<string> f(n/2);
	for (int i=0;i<n/2;++i){ 
		f[i]=v[i].name;
	}
	sort(f.begin(),f.end());
	for (int i=0;i<n/2;++i){ 
		cout<<f[i]<<endl;
	}
	
	return 0;
}
