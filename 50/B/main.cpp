#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

static long fac (long n){
	long acc=1;
	for (int i=1;i<=n;++i){
		acc=acc*i;
	}
	return acc;
}
int main(){
	string s;
	getline(cin,s);
	//
	multimap<char,int> m;
	set<char> sC;
	for (int i=0;i<s.size();++i){
		m.insert(make_pair(s[i],i));
		sC.insert(s[i]);
	}
	long  acc=0;
	for (set<char>::const_iterator it =sC.begin();
		it!=sC.end();++it){
		int num=m.count(*it);
		//cout<<num<<endl;
		//cout<<fac(num)
		//++acc;
		if (num>1){
			acc+=fac(num)/(fac(num-2));
			acc+=num;
		} else if (num==1)
			++acc;
	} 	
	cout<<acc<<endl;

	return 0;
}
