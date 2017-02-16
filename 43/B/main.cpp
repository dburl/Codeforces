#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	multiset<char> s;
	for (int i=0;i<s1.size();++i){
		s.insert(s1[i]);
	}
	for (int i=0;i<s2.size();++i){
		if (s2[i]!=' ' && (s.count(s2[i])==0)){
			cout<<"NO"<<endl;
			return 0;
		} else if (s2[i]!=' '){
			multiset<char>::const_iterator it = s.find(s2[i]);
			s.erase(it);
		}
	}
	cout<<"YES"<<endl;	


	return 0;
}
