#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> vP(n);
	vector<string> vF(m);
	map<string, int> mF;
	vector<int> vN;

	for (int i=0;i<n;++i){
		cin>>vP[i];
	}
	for (int i=0;i<m;++i){
		cin>>vF[i];
	}
	// build fruit map
	for (int i=0;i<m;++i){
		mF[vF[i]]=0;	
	}
	for (int i=0;i<m;++i){
		mF[vF[i]]+=1;	
	}
	for (map<string, int>::iterator it=mF.begin();it!=mF.end();++it){
		vN.push_back(it->second);	
	}
	//
	sort(vP.begin(),vP.end());
	sort(vN.begin(),vN.end());
	//for (int i=0;i<vN.size();++i){
	//	cout<<"vN[i]"<< vN[i]<< endl;
	//}	
	//for (int i=0;i<vP.size();++i){
	//	cout<<"vP[i]"<< vP[i]<< endl;
	//}	
	// minCalcul
	long long minim=0;
	int j=0;
	for (int i=vN.size()-1;i>=0;--i){
		minim+= vN[i]*vP[j];	
		++j;
	}
	//maxCalcul	
	long long maxim=0;
	j=vP.size()-1;
	for (int i=vN.size()-1;i>=0;--i){
		maxim+= vN[i]*vP[j];
		--j;	
	}
	cout<<minim<<" "<<maxim<<endl;

	return 0;
}
