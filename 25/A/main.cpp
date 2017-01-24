#include <iostream>
#include <vector>
using namespace std;


int main(){
	int n;
	cin>>n;
	vector<int> v(n),v1(n);
	vector<int> ev,od;
	for (int i=0;i<n;++i){
		cin>>v[i];
		v1[i]=v[i]%2;
		if(v1[i]==0){ev.push_back(i+1);}else {od.push_back(i+1);}
	}	
	//
	if (ev.size()==1){
		cout<<ev.front()<<endl;
	} else{
		cout<<od.front()<<endl;
	}
	

	return 0;
}
