#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;
void rotate(string& str){
	char t=str[0];
	for(int i=0;i<3;++i){
		str[i]=str[i+1];
	}
	str[3]=t;
//	cout<<str<<endl;
}
int main(){
	int n;
	cin>>n;
	map<string,vector<int> > m;
	for (int i=0;i<n;++i){
		string str="1234";
		cin>>str[0]>>str[1];
		cin>>str[3]>>str[2];
		string s;
		if (i<n-1)
			cin>>s;
		//
		if(m[str].empty()){
			rotate(str);
			if (m[str].empty()){
				rotate(str);
				if (m[str].empty()){
					rotate(str);
					m[str].push_back(i);
				}
			}
		}
	}
	int acc=0;
	for (auto it=m.begin();it!=m.end();++it){if (!it->second.empty())++acc;}
	cout<<acc<<endl;
	

	return 0;
}
