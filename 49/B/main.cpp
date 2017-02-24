#include <iostream>
#include <sstream>
using namespace std;


static long power (int base, int p){
	long accum=1;
	for (int i=0;i<p;++i){
		accum=accum*base;
	}
	return accum;
}
static int toDec(int  n, int base){
	stringstream ss;
	ss<<n;
	string s;
	ss>>s;
	long accum=0;
	for (int i=s.size()-1;i>=0;--i){
		accum+=(s[i]-'0')*power(base,s.size()-1-i);
	}
	return accum;
}

static string fromDec(long n, int base){
	string s;
	long rest=n;
	while(rest){
		char c='0'+rest&base;
		s.push_back(c);
		rest=rest/base;
	}
	return s;
}

int main(){
	int a,b;
	cin>>a>>b;
	//
	string aS,bS;
	stringstream ss1,ss2;
	ss1<<a;ss2<<b;
	ss1>>aS; ss2>>bS;
	int maxV=1;
	for (int i=0;i<aS.size();++i){
		if ((aS[i]-'0')>maxV){
			maxV=aS[i]-'0';
		}
	}
	for (int i=0;i<bS.size();++i){
		if ((bS[i]-'0')>maxV){
			maxV=bS[i]-'0';
		}
	}
	const int base=maxV+1;
	const string res= fromDec((toDec(a,base)+toDec(b,base)),base);
	cout<< res.size()<<endl;

	return 0;
}
