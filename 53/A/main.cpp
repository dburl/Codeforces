#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string s;
	cin>>s;
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	vector<string>::const_iterator it=lower_bound(v.begin(), v.end(), s);
	if (it!=v.end()&&
		it->size()>=s.size()&&
		it->substr(s.size())==s){
		cout<<*it<<endl;
	} else{
		cout<<s<<endl;
	}
	
	return 0;
}
