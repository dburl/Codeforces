#include<iostream>
#include<vector>
#include<algorithm>
#include "math.h"
#include <sstream>
using namespace std;

int main(){
	string n, m;
	cin>>n;
	cin>>m;
	string origM=m;
	// leading zero check
	if (m.size()==1){ // trivial case
		if (m==n){
			cout<<"OK"<<endl;	
			return 0;
		} else {cout<<"WRONG_ANSWER"<<endl; return 0;}
	}
	bool zeroOnWay=false;
	for (int i=0;i<m.size();++i){
		if (m[i]=='0') {zeroOnWay=true;}
		if (m[i]!='0') {
			if (zeroOnWay){
				cout<<"WRONG_ANSWER"<<endl; return 0;		
			} else {break;}
		}
	}
	//cout<< "here"<< endl;
	if (m.size()!=n.size()){cout<<"WRONG_ANSWER"<<endl; return 0;}
	// sorting
	sort(m.begin(),m.end());
	sort(n.begin(),n.end());
	//cout<< m<< endl;
	//cout<< n<< endl;
	// same letters check
	if (m!=n){cout<<"WRONG_ANSWER"<<endl; return 0;}
	stringstream ss;
	int zeroCount=0;
	int alreadyIntroduced=0;
	for(int i=0;i<n.size();++i){
		if (n[i]=='0'){
			++zeroCount;	
		} else {
			if (alreadyIntroduced==1){
				for (int j=0;j<zeroCount;++j){
					ss<<"0";		
				}
				ss<<n[i];
				++alreadyIntroduced;
			} else{ ss<<n[i]; ++alreadyIntroduced;}
		}
	}
	string corr= ss.str(); 
	//cout << corr<< endl;
	for (int i=0; i<origM.size();++i){
		if (origM[i]!=corr[i]){cout<<"WRONG_ANSWER"<<endl; return 0;}	
	}
	cout<< "OK"<< endl;
	
	
	return 0;

}
