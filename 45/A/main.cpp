#include <iostream>
#include <map>
using namespace std;

int main(){
	int n; string s;
	cin>>s; cin>>n;
	map<string,int> m;
	m.insert(make_pair("January",1));
	m.insert(make_pair("February",2));
	m.insert(make_pair("March",3));
	m.insert(make_pair("April",4));
	m.insert(make_pair("May",5));
	m.insert(make_pair("June",6));
	m.insert(make_pair("July",7));
	m.insert(make_pair("August",8));
	m.insert(make_pair("September",9));
	m.insert(make_pair("October",10));
	m.insert(make_pair("November",11));
	m.insert(make_pair("December",0));
	int month_now = m[s];
	int month_search= (month_now+n)%12;
	for (map<string,int>::const_iterator it=m.begin();it!=m.end();++it){
		if (it->second==month_search){
			cout<<it->first<<endl;
			return 0;
		}
	}


	return 0;
}
