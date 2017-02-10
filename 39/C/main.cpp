#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Cr{
	int id;
	long c;
	long r;
	long  l;
	bool excl;
	int cross;
};

bool inter(Cr& a, Cr& b){
	return ((a.l>b.l && a.r>b.r && a.l<b.r) || (a.l<b.l && a.r<b.r && a.r>b.l));
}

bool comp (Cr& a, Cr& b){return a.cross>b.cross;}
bool compID (Cr& a, Cr& b){return a.id<b.id;}
int main(){
	int n;
	vector<Cr> v(n);
	for (int i=0;i<n;++i){
		v[i].id=i+1;
		cin>>v[i].c;
		cin>>v[i].r;
		v[i].l=v[i].c-v[i].r;
		v[i].r=v[i].c+v[i].r;
	v[i].excl=false;
	v[i].cross=0;
	}
	int totExl=0;
	bool valid=true;
	do{
	valid=true;
	for (int i=0;i<n;++i){
		for (int j=i+1;j<n;++j){
			if (inter(v[i],v[j])){
				v[i].cross+=1;
				v[j].cross+=1;
				valid=false;
			}
		}
	}
	sort(v.begin(),v.end(),comp);
	bool excl=false;
	for (int i=0;i<n;++i){
		if (!excl && !v[i].excl){v[i].excl=true;excl=true;++totExl;}
		v[i].cross=0;
	}

	}while(!valid);	
	sort(v.begin(),v.end(),compID);
	cout<<v.size()-totExl<<endl;
	for (int i=0;i<n;++i){
		if(v[i].excl) cout<<v[i].id;
		cout<<((v[i].excl)?"":" ");
	}
	cout<<endl;

	return 0;
}
