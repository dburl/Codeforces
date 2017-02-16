#include <iostream>
#include <map>
using namespace std;


int main(){
	int n=0;
	cin>>n;
	map<string,int> m;
	for (int i=0;i<n;++i){
		string tmp;
		cin>>tmp;
		if(!(m.insert(make_pair(tmp,1)).second)){
			m[tmp]+=1;
		}
	}
	//
	if (m.size()>1 && m.begin()->second < (++m.begin())->second){
		cout<<(++m.begin())->first<<endl;
	} else {
		cout<<m.begin()->first<<endl;
	}
	


	return 0;
}
