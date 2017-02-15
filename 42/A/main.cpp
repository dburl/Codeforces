#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,V;
	cin>>n>>V;
	vector <int> v(n),b(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	for (int i=0;i<n;++i){
		cin>>b[i];
	}
	//
	int sumI=0;
	for (int i=0;i<n;++i){
		sumI+=v[i];
	}
	float x=(float)V/(float)sumI;
	//cout<<"x "<< x<<endl;
	//cout<<"sumI "<<sumI<<endl;
	float fin=x;
	for (int i=0;i<n;++i){
		if (x*v[i]>b[i]){
			float p=(float)b[i]/(float)v[i];
			//cout<<"p "<<p<<endl;
			if (p<fin){
				fin=p;
			}
		}
	}
	cout<<fin*sumI<<endl;

	return 0;
}

