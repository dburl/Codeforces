#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct T{
	int id;	
	int val;
};

bool compF(T a, T b){return a.val<b.val;}
int main(){
	int n;
	cin>>n;
	vector<T> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i].val;
		v[i].id=i+1;
	}
	//
	sort(v.begin(),v.end(), compF);
	for (int i=0;i<n;++i){
		cout<<"*"<<v[i].id<<" ->"<<v[i].val<<endl;
	}
	T a2=v[0];
	T a1, a3;
	bool lb=false,rb=false;
	for (int i=0;i<n;++i){

		if((v[i].id>a2.id) && (v[i].val > a2.val)){
			cout<<"r="<<v[i].id<<endl;
			a3=v[i];
			rb=true;
		} 
		if((v[i].id<a2.id) && (v[i].val > a2.val)){
			cout<<"l="<<v[i].id<<endl;
			a1=v[i];
			lb=true;
		}
		if (lb&&rb){
			break;
		}
	}
	if (lb&&rb){
	cout<<3<<endl;
	cout<<a1.id<<" "<<a2.id<<" "<<a3.id<<endl;
	}else{
		cout<<"0"<<endl;
	}

	return 0;
}
