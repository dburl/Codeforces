#include <iostream>
#include <vector>
using namespace std;


int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	//
	if (v.size()<2){
		cout<<"NO"<<endl;
		return 0;
	}




	return 0;
}
