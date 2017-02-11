#include <iostream>
#include <map>
#include <iterator>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
class Pl{
	public:
	Pl(string name, int score):name(name),points(score){}
	string name;
	long points;
	vector<pair<int,int> > history;
};

int whenM(const Pl& p, int m){
	for (int i=0;i<p.history.size();++i){
		if (p.history[i].first>=m){
			return p.history[i].second;
		}
	}
}
bool comp(const Pl& a, const Pl& b){
	if (a.points!=b.points){
		return a.points>b.points;
	} else {
		return whenM(a, a.points)<whenM(b,a.points);
	}
}

int main(){
	int n;
	cin>>n;
	map<string,Pl> m;
	for(int i=0;i<n;++i){
		string nameTmp; int scoreTmp;
		cin>>nameTmp; cin>>scoreTmp;
		Pl tmp(nameTmp,scoreTmp);
		pair<map<string,Pl>::iterator,bool> p=
			m.insert(make_pair(nameTmp, tmp));
		if (!p.second){
			p.first->second.points+=scoreTmp;
		} 
		p.first->second.history.push_back(make_pair(p.first->second.points,i));
	}
	vector<Pl> v;
	for (map<string,Pl>::const_iterator it=m.begin();it!=m.end();++it){
		v.push_back(it->second);
	}
	sort (v.begin(),v.end(), comp);
	cout<< v.front().name<<endl;

	return 0;
}
