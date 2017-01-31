#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Change{
public: 
	string ab;
	int c;
	int id;
};

bool comp(Change& a, Change& b){
	return a.c<b.c;
}

int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	int n;
	cin>>n;
	
	map< string, int > m;
	vector<Change> v(n);
	for (int i=0;i<n;++i){
		char a,b;
		int c;
		cin>>a>>b>>c;
		string s;
		s.push_back(a);
		s.push_back(b);
		m[s]=c;
		v[i].ab=s;
		v[i].c=c;
	}
	sort(v.begin(),v.end(),comp);
	for (int i=0;i<v.size();++i){
		//m[v[i].ab].id=i;
	}
	long costT=0;
	for (int i=0;i<s1.size();++i){
		if (s1[i]!=s2[i]){
			string op1(2,s2[i]); //s2->s1
			op1[1]=s1[i];
			string op2(2,s1[i]);
			op2[1]=s2[i];
			if (m.find(op1)!=m.end()&& (m[op1]<m[op2]||m.find(op2)==m.end())){
				costT+=m[op1]; s2[i]=s1[i];
			} else if (m.find(op2)!=m.end() ){
				costT+=m[op2]; s1[i]=s2[i];
			}
		}
	}
	cout<< costT<<endl;
	cout<<s1<<endl;

	return 0;
}
