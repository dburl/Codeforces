#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Coin{
	char nam;
	int w;

};
bool comp(const Coin&a, const Coin& b) {return a.w<b.w;}

int main(){
	map<char,Coin> m;
	m['A']=Coin{'A',0};
	m['B']=Coin{'B',0};
	m['C']=Coin{'C',0};
	for (int i=0;i<3;++i){
		string str;
		cin>>str;
		char a,b,s;
		a=str[0];b=str[2];s=str[1];
		//
		//
		if (s=='<'){
				m[a].w-=1;
		} else {
			m[b].w-=1;
		}
	}
	vector<Coin> v;
	v.push_back(m['A']);
	v.push_back(m['B']);
	v.push_back(m['C']);
	sort(v.begin(),v.end(),comp);
	for (int i=1;i<3;++i){
		if (v[i-1].w==v[i].w){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	for (int i=0;i<3;++i){
		cout<<v[i].nam;
	}
	cout<<endl;

	return 0;
}
