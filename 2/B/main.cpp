#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

struct P{
	P(string c,long long sum, int x, int y):path(c),sum(sum),x(x),y(y){}
	P():path(""),sum(0),x(0),y(0){}
	string path;
	long long sum;
	int x;
	int y;
	const bool operator < (const P& b) const {return this->path<b.path;}
	
};

int numZ(const P& p){
	int pos=0;
	long long sum=p.sum;
	while(sum/10 !=0){
		if (sum%10!=0){
			break;
		}
		sum=sum/10;	
		++pos;
	}
	return pos;
}
bool comp(const P& a, const P& b){return numZ(a)<numZ(b);}

int main(){
	int n;
	cin>>n;
	cout<< "Started"<<endl;
	vector<vector<int> > v(n);
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){	
			int tmp;
			cin>>tmp;
			v[i].push_back(tmp);
		}
	}
	set<P> s;
	P fst("",v[0][0],0,0);
	s.insert(fst);
	
	for (int i=0;i<(2*n-1);++i){
		for (set<P>::iterator it=s.begin();it!=s.end();++it){
			P a(*it);
			if ((a.y+1)<n){
				a.path.push_back('D');
				a.sum+=v[a.y+1][a.x];
				a.y+=1;	
				s.insert(a);
			}
			P b(*it);
			if ((b.x+1)<n){
				b.path.push_back('R');
				b.sum+=v[b.y][b.x+1];
				b.x+=1;
				s.insert(b);
			}
			if (it->x!=(n-1) || it->y!=(n-1)){
				s.erase(it);
			}
		}
	}
	cout<< s.size()<<endl;
	vector<P> pv(s.size());
	int i=0;
	for (set<P>::iterator it=s.begin() ;it!=s.end();++it,++i){
		pv[i]=*it;
	}
	sort(pv.begin(),pv.end(),comp);
	cout<<numZ(pv.front())<<endl;
	cout<<pv.front().path<<endl;
	return 0;
}
