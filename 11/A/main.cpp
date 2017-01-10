#include<iostream>
#include<vector>

using namespace std;

int main(){
	unsigned long n=0, d=0;
	cin>> n>> d;
	vector<unsigned long> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	//	
	
	unsigned long count=0;
	if (n<2){
		cout<<count<<endl;
		return 0;
	}

	for (int i=0;i<n-1;++i){
		while(v[i+1]<=v[i]){
			//cout<<"v[i]="<<v[i]<<endl;
			//cout<<"v[i+1]="<<v[i+1]<<endl;
			unsigned long diff = v[i]-v[i+1];
			unsigned long toAdd= diff/d;
			//if (diff%d==0){
			//	v[i+1]+=toAdd*d;
			//	count+=toAdd;
			//} else {
				v[i+1]+=(toAdd+1)*d;
				count+=(toAdd+1);		
			//}

		}
	}
	cout<<count<<endl;	
	

	return 0;
}
