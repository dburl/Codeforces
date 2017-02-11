#include <iostream>
#include <vector>
using namespace std;


int main(){
	vector<bool> v(3);
	for (int i=0;i<3;++i){
		int tmp;	
		cin>>tmp;
		v[i]=(bool)tmp;
	}
	for (int i=0;i<3;++i){
		int tmp;
		cin>>tmp;;
		if ((bool)tmp==v[i]){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;




	return 0;
}
