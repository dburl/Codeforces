#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

struct Dam{
	long long id;
	int b;
	int i;
	int r;
	};

bool compB (Dam a,Dam b) { return (a.b<b.b); }
bool compI (Dam a,Dam b) { return (a.i<b.i); }
bool compR (Dam a,Dam b) { return (a.r<b.r); }

int main(){
	long long n;
	cin>>n;
	vector<long long> bv(n), rv(n), iv(n) ;
	vector<Dam> v;
	map<long long, long long> mB, mR, mI;
	for(long long i=0;i<n;++i){
		cin>>bv[i];	
	}
	for(long long i=0;i<n;++i){
		cin>>iv[i];	
	}

	for(long long i=0;i<n;++i){
		cin>>rv[i];	
	}
	// read done
	for(long long i=0;i<n;++i){
		Dam tmp={i, bv[i],iv[i],rv[i]};
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), compB);
	long long maxB=0;
	mB[v[0].id]=0;	
	for(long long i=1;i<n;++i){
		if (v[i].b>v[i-1].b){
			maxB++;
			mB[v[i].id]=maxB;			
		} else{	mB[v[i].id]=maxB;}
	}
	long long maxR=0;
	mR[v[0].id]=0;	
	sort(v.begin(), v.end(), compR);
	for(long long i=1;i<n;++i){
		if (v[i].r>v[i-1].r){
			maxR++;
			mR[v[i].id]=maxR;			
		} else{	mR[v[i].id]=maxR;}	
	}
	long long maxI=0;
	mI[v[0].id]=0;	
	sort(v.begin(), v.end(), compI);
	for(long long i=1;i<n;++i){
		if (v[i].i>v[i-1].i){
			maxI++;
			mI[v[i].id]=maxI;			
		} else{	mI[v[i].id]=maxI;}
	}	
	long long count=0;
	for (long long i=0;i<n;++i){
		//bool dead=false;
		for (long long j=0;j<n;++j){
			if ( (mR[i]<mR[j]) && (mI[i]<mI[j])&&(mB[i]<mB[j])){
		//		dead=true;
				count++;
				break;
			}
		}
		//if 
	}
	cout<< count<< endl;


	return 0;
}
