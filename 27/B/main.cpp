#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct Pl{
	int id;
	//<int>;
	set<int> won;
	set<int> lost;
};

int main(){
	int n;
	cin>>n;
	map<int,Pl> v;
	for(int i=0;i<(((n*(n-1))/2)-1);++i){
		int lw, rl;
		cin>>lw>>rl;
		v[lw].id=lw;
		v[rl].id=rl;
		v[lw].won.insert(rl);
		v[rl].lost.insert(lw);
	}
	//
	//find who didn't play
	vector<Pl> c;
	for (map<int,Pl>::const_iterator it=v.begin();it!=v.end();++it){
		for (map<int,Pl>::const_iterator jt=v.begin();jt!=v.end();++jt){
			bool cond1= it->second.won.find(jt->second.id)==it->second.won.end();
			bool cond2= it->second.lost.find(jt->second.id)==it->second.lost.end();
			bool cond3 = !(it->second.id==jt->second.id);
			if (cond1&&cond2&&cond3){
				c.push_back(it->second);	
			}
		}
	}
	//
	//cout<<"2="<<c.size()<<endl;
	//
	Pl a, b;
	a=c[0]; b=c[1];
	for (set<int>::const_iterator it=a.won.begin();it!=a.won.end();++it){
		if (b.lost.find(*it)!=b.lost.end()){
			cout<<a.id<<" "<<b.id<<endl;
			return 0;
		}
	}
	for (set<int>::const_iterator it=b.won.begin();it!=b.won.end();++it){
		if (a.lost.find(*it)!=a.lost.end()){
			cout<<b.id<<" "<<a.id<<endl;
			return 0;
		}
	}
	cout<<a.id<<" "<<b.id<<endl;



	return 0;
}
