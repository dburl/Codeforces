#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Emp{
	int id;
	long q;
};

bool compE(Emp a, Emp b){return a.q>b.q;}

struct App{
	int id;
	long a;
	long b;
	long c;
};

bool compA(App a, App b){return a.c<b.c;}

bool wants(vector<App>& v,int boss, int emp){
	for (int i=0;i<v.size();++i){
		if (v[i].a==emp && v[i].b==boss){
			return true;		
		}
	}
	return false;
}

vector<App> canWorkFor(vector<App>& v,int me){
	vector<App> tmp;
	for (int i=0;i<v.size();++i){
		if (v[i].a==me){
			tmp.push_back (v[i]);	
			//cout<<me<<" can work for "<<v[i].b<< " for " <<	v[i].c<<endl;
		}
	}
	return tmp;
}

int main(){
	int n,m;
	cin>>n;
	vector<Emp> ve(n);
	for (int i=0;i<n;++i){
		ve[i].id=i+1;
		cin>>ve[i].q;
	}		
	cin>>m;
	vector<App> va(m);

	for (int i=0;i<m;++i){
		va[i].id=i+1;
		cin>>va[i].b>>va[i].a>>va[i].c;
	}
	//
	sort(ve.begin(), ve.end(), compE);
	for (int i=0;i<ve.size();++i){
		//cout<<ve[i].q<<endl;
	}
	sort(va.begin(), va.end(), compA);
	//
	//boss=ve[0]
	vector<int> inTree;
	long cost=0;
	inTree.push_back(ve[0].id);// boss
	//cout<<"boss"<<ve[0].id<<endl;
	for (int p=1;p<ve.size();++p){
		//cout<<"check "<<ve[p].id<<endl;
		vector<App> bosses= canWorkFor(va,ve[p].id);
		//cout<<"potential bosses: "<< bosses.size()<<endl;
		int foundBoss=-1;
		for (int j=0;j<bosses.size();++j){
			vector<int>::iterator it=
				find(inTree.begin(),inTree.end(),bosses[j].b);
			if (it!=inTree.end()){
				//found boss - cheapest salary
				cost+= bosses[j].c;
				foundBoss =bosses[j].b;
				//cout<<bosses[j].b<<"->"<<bosses[j].a<< endl;
				break;
			}
		}
		if(foundBoss<0){cout<<"-1"<<endl;return 0;} 
		inTree.push_back(ve[p].id);
	}
	cout<<cost<<endl;

	return 0;
}
