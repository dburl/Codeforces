#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
	int n,m;
	char c;
	cin>>n>>m>>c;
	vector<string> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	//cout<< "read"<<endl;
	map<char, set<char> > x;
	for (int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			//cout<<i<<j<<endl;
			if (v[i][j]!='.'){
				if ((j+1)<m) x[v[i][j]].insert(v[i][j+1]);
				if ((i+1)<n) x[v[i][j]].insert(v[i+1][j]);
				if ((j-1)>=0) x[v[i][j]].insert(v[i][j-1]);
				if ((i-1)>=0) x[v[i][j]].insert(v[i-1][j]);
			}
		}		
	}
	x[c].erase(c);
	x[c].erase('.');
	cout<< x[c].size()<< endl;

	return 0;

}
