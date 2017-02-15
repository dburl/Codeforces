#include <iostream>
#include <vector>
#include <set>
using namespace std;

int outB (int v){
	if (v<0)
		return 0;
	else if (v>7)
		return 7;
	else 
		return v;
}

struct Pos{
	Pos(){}
	Pos(int x, int y):x(outB(x)),y(outB(y)){}
	int x;
	int y;
	const 	bool operator <(const Pos& b)const {
		if (x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
	const bool operator ==(const Pos&b)const{return x==b.x&&y==b.y;}
};
set<Pos> rook(const Pos& p, const Pos& stop){
	set<Pos> res;
	for (int i=0;i<8;++i){
		if (stop==Pos(p.x+i,p.y)) break;
		res.insert(Pos(p.x+i,p.y));
	}
	for (int i=0;i<8;++i){
		if (stop==Pos(p.x-i,p.y)) break;
		res.insert(Pos(p.x-i,p.y));
	}
	for (int i=0;i<8;++i){
		if (stop==Pos(p.x,p.y+i)) break;
		res.insert(Pos(p.x,p.y+i));
	}
	for (int i=0;i<8;++i){
		if (stop==Pos(p.x,p.y-i)) break;
		res.insert(Pos(p.x,p.y-i));
	}
	res.erase(p);
	return res;
}

set<Pos> king(const Pos& p){
	set<Pos> res;
	res.insert(Pos(p.x+1,p.y));
	res.insert(Pos(p.x-1,p.y));
	res.insert(Pos(p.x,p.y+1));
	res.insert(Pos(p.x,p.y-1));
	res.insert(Pos(p.x+1,p.y+1));
	res.insert(Pos(p.x-1,p.y-1));
	res.insert(Pos(p.x+1,p.y-1));
	res.insert(Pos(p.x-1,p.y+1));
	return res;
}

int main(){	
	vector<Pos> v(4);
	for (int i=0;i<4;++i){
		char a; int b;
		cin>>a>>b;
		v[i].y=b;
		v[i].x=(int)a- (int)'a';
	}
	set<Pos> occ;
	for (int i=0;i<2;++i){
		set<Pos> p= rook(v[i],v[2]);
		occ.insert(p.begin(),p.end());
	}
	set<Pos> p= king (v[2]);
	occ.insert(p.begin(),p.end());
	occ.insert(v[2]);

	for (set<Pos>::iterator it=occ.begin();it!=occ.end();++it){
		//cout<<"x="<<it->x<<" y="<<it->y<<endl;
	}
	set<Pos> c = king (v[3]);
	for (set<Pos>::iterator it=c.begin();it!=c.end();++it){
		//cout<<"Kx="<<it->x<<" Ky="<<it->y<<endl;
		Pos tmp =*it;
		if (occ.find(tmp)==occ.end()){
			cout<<"OTHER"<<endl;
			return 0;
		}
	}
	cout << "CHECKMATE"<<endl;
	


	return 0;
}
