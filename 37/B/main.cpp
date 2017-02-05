#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct Sc{
	int id;
	int pow;
	int dmg;
};

bool decrComp(Sc& a, Sc& b){return a.pow>b.pow;}

int main(){
	int N, maxI, reg;
	cin>>N>>maxI>>reg;
	vector<Sc> v(N);
	for (int i=0; i<N;++i){
		cin>>v[i].pow>>v[i].dmg;
		v[i].id=i+1;
	}
	sort(v.begin(),v.end(),decrComp);
	long long time=0;
	int health=maxI;
	int damSec=0;
	int notYetUsed=0;
	bool possible=false;
	vector<long long> timeUse;
	while(health>0){
		if (reg>=damSec && 
		(notYetUsed==v.size() || v[notYetUsed].pow<((health*100)/maxI))){
			break;
		}
		//1
		//cout<<"\t H:"<<health;
		health-=damSec;
		//cout<<"->"<<health<<endl;
		//2
		health=min(maxI, health+reg);
		//3
		if (notYetUsed<v.size() && v[notYetUsed].pow>=((health*100)/maxI)){
			//cout<<"Sc used:"<< notYetUsed<<" "<<v[notYetUsed].pow<< " "<<((health*100)/maxI)<<endl;
			damSec+=v[notYetUsed].dmg;
			timeUse.push_back(time);
			++notYetUsed;
		}
		++time;
	}
	if (health<=0){possible=true;}
	if (!possible){
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
		cout<<time-1<<" "<<notYetUsed<<endl;
		for (int i=0;i<timeUse.size();++i){
			cout<<timeUse[i]<<" "<<v[i].id<<endl;
		}
	}

	return 0;
}
