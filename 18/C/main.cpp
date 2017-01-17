#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int sum(vector<int>::iterator a,vector<int>::iterator b){
	long tmp=0;
	while(a!=b){
		tmp+=*a;
		++a;
	}
	//cout<< tmp<<endl;
	return tmp;
}


int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	//
	int count=0;

	if(!v.empty()){
		long sumR=sum(v.begin()+1,v.end());
		long sumL=v[0];
		if (sumR==sumL){ ++count;}

		for(int i=1;i<n-1;++i){
			sumL+=v[i]; sumR-=v[i];
			if (sumR==sumL){ ++count;}
		}
	}
	cout<<count<<endl;



	return 0;
}
