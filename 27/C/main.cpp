#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct T{
	int id;	
	long val;
};

bool compF(T a, T b){return a.val<b.val;}
bool compF2(T a, T b){return a.val>b.val;}
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
		//cout<<"*"<<v[i].id<<" ->"<<v[i].val<<endl;
	}
	T a1, a2, a3;
	bool lb,rb;
	for(int j=0;(j<2)&&(j<n)&&(!(lb&&rb));++j){
	a2=v[j];
	lb=false;rb=false;
		for (int i=0;i<n;++i){
			if((v[i].id>a2.id) && (a2.val <= v[i].val  )){
				//cout<<"r="<<v[i].id<<endl;
				a3=v[i];
				rb=true;
			} 
			if((v[i].id<a2.id) && (a2.val <= v[i].val  )){
				//cout<<"l="<<v[i].id<<endl;
				a1=v[i];
				lb=true;
			}
			if (lb&&rb){
				break;
			}
		}
	}
	if (!(lb&&rb)){
		sort(v.begin(),v.end(), compF2);
		for (int i=0;i<n;++i){
			//cout<<"-"<<v[i].id<<" ->"<<v[i].val<<endl;
		}
		for(int j=0;(j<2)&&(j<n)&&(!(lb&&rb));++j){
			a2=v[j];	
			lb=false,rb=false;
			for (int i=0;i<n;++i){
				if((v[i].id>a2.id) && (v[i].val <= a2.val)){
					//cout<<"r="<<v[i].id<<endl;
					a3=v[i];
					rb=true;
				} 
				if((v[i].id<a2.id) && (v[i].val <= a2.val)){
					//cout<<"l="<<v[i].id<<endl;
					a1=v[i];
					lb=true;
				}
				if (lb&&rb){
					break;
				}
			}
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
