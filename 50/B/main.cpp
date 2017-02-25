#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	//
	multimap<char,long> m;
	set<char> sC;
	for (int i=0;i<s.size();++i){
		m.insert(make_pair(s[i],i));
		sC.insert(s[i]);
	}
	long  long acc=s.size();
	for (set<char>::const_iterator it =sC.begin();
		it!=sC.end();++it){
		long long num=0;
		acc+=num*num;
	} 	
	cout<<acc<<endl;

	return 0;
}
