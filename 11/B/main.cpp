#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<long long> jump(const vector<long long>& v, unsigned step, vector<long long>& finalV){
	vector<long long> newV;
	for (unsigned i=0;i<v.size();++i){
		//cout<<v[i]<<", ";
		if (step==1)	finalV.push_back(v[i]+step);
		if (step==1) finalV.push_back(v[i]-step);

		newV.push_back(v[i]+step);
		newV.push_back(v[i]-step);
	}
	//cout<<endl;
	return newV;
}


bool check(const vector<long long>& v){
	for (unsigned i=0;i<v.size();++i){
		//cout<<v[i]<<" ";
		if(v[i]==0){return true;}
	}
	//cout<<endl;
	return false;
}

int main(){
	long long finX;
	cin>>finX;

	vector<long long> v(1,finX);
	vector<long long> vOrig(1,finX);
	// estim uppter bound of step
	
	
	unsigned maxStep=sqrt(3*finX)+1;
	unsigned minStep=maxStep+1;
	
	if (check(v)) {cout<<0<<endl; return 0;}
	for(long long i=maxStep;i>0;--i){
		//cout<<"step="<<i<<endl;
		v=vOrig;
		long long step=i;
		vector<long long> finalV(1,finX);
		while (step>0){
			v=jump(v, step, finalV);
			--step;			
		}
		if (check(finalV)  && i<minStep) {minStep=i;}
	}
	cout<<minStep<<endl;

	return 0;
}
