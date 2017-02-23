#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

map<string, set<string> > m;
bool win(const string& s1, const string s2){
	return m[s1].find(s2)!=m[s1].end();
}

bool beats(const vector<string>& v, int i){
	const string& c1=v[(i+1)%3];
	const string& c2=v[(i+2)%3];
	return  (win(v[i],c1) && win(v[i],c2));
}

int main(){
	m["rock"]=set<string>();
	m["rock"].insert("scissors");
	m["scissors"]=set<string>();
	m["scissors"].insert("paper");
	m["paper"]=set<string>();
	m["paper"].insert("rock");
	//
	vector<string> v(3);	
	for (int i=0;i<3;++i){
		cin>>v[i];
	}
	//
	for (int i=0;i<3;++i){
		if (beats(v,i)){
			switch(i){
				case 0:
					cout<<"F"<<endl;
					break;
				case 1:
					cout<<"M"<<endl;
					break;
				case 2:
					cout<<"S"<<endl;
					break;	
				default:		
					cout<<endl;
			}
			return 0;
		}
	}
	cout<<"?"<<endl;

	return 0;
}
