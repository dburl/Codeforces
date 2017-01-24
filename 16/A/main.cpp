#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<string> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];		
	}
	//
	char prevC=v[0][0];
	for (int i=0;i<n;++i){	
		bool horiz=true;
		char c= v[i][0];
		if (i>0){
			if  (prevC==c){
				cout<<"NO"<<endl;
				return 0;
			} else {
				prevC=c;
			}
		}
		if (c<'0'||c>'9'){
			//cout<<"wrong color"<<endl;
			cout<<"NO"<<endl;
			return 0;
		}
		for (int j=1;j<m;++j){
			if (v[i][j]!=c){
				horiz=false;
				cout<<"NO"<<endl;
				return 0;	
			}
		}
	}
	cout<<"YES"<<endl;


	return 0;
}
