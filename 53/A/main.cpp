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
	//	for(int i=0;i<n;++i){
	//	cout<<v[i]<<" ";
	//}
	vector<string>::const_iterator it=lower_bound(v.begin(), v.end(), s);
	//cout<<*it;
	if (it!=v.end()&&
		it->size()>=s.size()&&
		it->substr(0,s.size())==s){
		//cout<<1<<endl;
		cout<<*it<<endl;
	} else{
		cout<<s<<endl;
	}
	
	return 0;
}
