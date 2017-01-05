#include <iostream>
#include <map>
#include <iterator>
#include <sstream>
#include <vector>
using namespace std;

int main(){
	unsigned n;
	cin>>n;
	typedef map<string,unsigned> M2N;
	M2N names;
	vector<string> outs;
	for(unsigned i=0;i<n;++i){
		string str;
		cin>> str;
		M2N::iterator it= names.find(str);
		if (it!=names.end()){ // already exists
			stringstream ss;
			ss<<str<<(it->second+1);
			it->second+=1;
			string newName;
			ss>> newName;
			names[newName]=0;
				
			outs.push_back(newName);
		} else { // new name
			names[str]=0;
			outs.push_back("OK");	
		}
	}
	for (vector<string>::const_iterator it=outs.begin();it!=outs.end();++it){
		cout<<*it<< endl;	
	}
	return 0;
}
