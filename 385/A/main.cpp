#include <iostream>
#include <set>
using namespace std;
int main(){
	string str;
	cin>>str;
	set<string> s;
	s.insert(str);
	for (int i=0;i<str.size()+1;++i){
		string tmp;
		tmp.push_back(str[str.size()-1]);
		for (int j=0;j<str.size()-1;++j){
			tmp.push_back(str[j]);
		}
		s.insert(tmp);
		str=tmp;
		//cout<<str<<endl;
	}
	cout<<s.size()<<endl;

	return 0;
}