#include<iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Env{
	public:
		unsigned w;
		unsigned h;
		unsigned id;
		bool operator < (const Env& v) const {
			return this->w<v.w && this->h<v.h;
		};	
};

int main(){
	unsigned n, w, h;
	cin>>n>>w>>h;
	vector<Env>  envs;
	for (unsigned i=0;i<n;++i){
		Env v;
		cin>> v.w >>v.h;
		v.id=i+1;
		envs.push_back(v);
	}
	sort(envs.begin(), envs.end());
	
	vector<Env>  e2;
	for (int i=0;i<envs.size();++i){
		//cout<< envs[i].id<< endl;		
		if(i==0 )
			e2.push_back(envs[i]);
		if (i>0 && e2.back().h<envs[i].h&& e2.back().w<envs[i].w){
			e2.push_back(envs[i]);
		}
	}
	int start=-1;
	for (int i=0;i<e2.size() && start==-1;++i){
		if(h<envs[i].h && w<envs[i].w){start=i;} 
	}
	if(start>=0)
		cout<< e2.size()-start<< endl;		
	else
		cout<< 0<< endl;		
	for (int i=start;i<e2.size();++i){
		cout<< e2[i].id<< " ";		
	}
		cout<< endl;			
	return 0;
}
