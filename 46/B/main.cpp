#include <iostream>
#include <vector>
using namespace std;

int take(vector<int>& v, int p){
	for (int i=0;i<5;++i){
		if ((p+i<5)&&(v[p+i]>0)){
			v[p+i]-=1;
			return p+i;
		} else if (((p-i)>=0)&&(v[p-i]>0)) {
			v[p-i]-=1;
			return p-i;
		}

	}
	return -1;
}

int main(){
	vector<int> t(5);
	cin>> t[0]>> t[1]>> t[2]>> t[3]>>t[4];
	int K;
	cin>>K;
	vector<string> o(K);
	for (int i=0;i<K;++i){	
		string s;
		cin>>s;
		int pref=-1;
		if (s=="S"){
			pref=0;	
		} else if(s=="M") {
			pref=1;
		} else if (s=="L"){
			pref=2;
		} else if (s=="XL"){
			pref=3;
		} else if (s=="XXL"){
			pref= 4;
		}
		string out;
		switch(take(t,pref)){
			case 0:
				out="S";
				break;
			case 1: 
				out="M";
				break;
			case 2:
				out="L";
				break;
			case 3:
				out="XL";
				break;
			case 4:
				out="XXL";
				break;
			default:
				out="err";
				break;
		}
		o[i]=out;
	}
	for (int i=0;i<K;++i){
		cout<<o[i]<<endl;
	}
	return 0;
}
