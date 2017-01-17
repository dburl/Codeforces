#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int sum(vector<long long>::iterator a,vector<long long>::iterator b){
	long long tmp=0;
	while(a!=b){
		tmp+=*a;
		++a;
	}
	//cout<< tmp<<endl;
	return tmp;
}


int main(){
	long long n;
	cin>>n;
	vector<long long> v(n);
	for (long long i=0;i<n;++i){
		cin>>v[i];
	}
	//
	long long count=0;

	if(v.size()>1){
		long long sumR=sum(v.begin()+1,v.end());
		long long sumL=v[0];
		if (sumR==sumL){ ++count;}

		for(long long i=1;i<n-1;++i){
			sumL+=v[i]; sumR-=v[i];
			if (sumR==sumL){ ++count;}
		}
	}
	cout<<count<<endl;



	return 0;
}
