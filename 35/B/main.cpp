#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;





bool addRemove(const string& s){
	return s.substr(0,2)=="+1";
}
map<pair<int,int>,string > c2b;
map<string, pair<int,int> > b2c;
ofstream outF ("output.txt");

void add(const string& s,int n,int m){
	stringstream ss(s);
	int x,y; string name;
	ss>>x>>y>>name;
	//
	map<pair<int, int>,string>::iterator it=c2b.find(make_pair(x,y));
	while(it!=c2b.end()||(x==n&&y==m)){
		if (y==m){y=1;++x;}else {++y;}
	}
	if (!(x==n&&y==m)) {
		c2b[make_pair(x,y)]=name;
		b2c[name]=make_pair(x,y);
	}
}

void remove(const string& name){
	map<string,pair<int,int> >::const_iterator it=b2c.find(name);
	if (it!=b2c.end()){
		outF<<it->second.first<<" "<<it->second.second<<endl;
	} else {
		outF<<"-1 -1 "<<endl;
	}
	c2b.erase(it->second);
	b2c.erase(name);
	
}
int main(){
	ifstream inF("input.txt");
	int n,m,k;
	outF.is_open();
	if (inF.is_open()){
		inF>>n>>m>>k;
		for (int i=0;i<k;++i){
			string s;
			inF>>s;
			if (addRemove(s)) {add(s.substr(4,s.size()-3),n,m);}
			else {remove(s.substr(4,s.size()-3));}
		}
	}
	outF.close();
	return 0;
}
