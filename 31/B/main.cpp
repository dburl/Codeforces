#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	string s;
	cin>>s;
	// 
	int phase=0;
	int start=0;
	vector<string> all;
	for (int i=0; i<s.size(); ++i){
		if (phase==0 && s[i]!='@'){continue;}
  		if (phase==0 && s[i]=='@'){
			if ((i-start)==0){
				cout<<"No solution"<<endl;
				return 0;			
			}
			phase=1;
			if (i==(s.size()-1)){cout<<"No solution"<<endl;
				return 0;}
			continue;
		}
		if (phase==1 && s[i]!='@'){
			all.push_back(s.substr(start,i-start+1)); 
			phase=0;  
			start=i+1;
			continue;
		}
	}
	if (phase==1){
		s.substr(start,s.size()-start);
	}
	if (!all.empty()){
	for (vector<string>::const_iterator it=all.begin();it!=all.end();++it){
		cout<<*it;	
		if( (++it)!=all.end() ){cout<<",";--it;} else{--it;}
	}
	cout<<endl; return 0;
	}
	cout<<"No solution"<<endl;

	return 0;
} 
