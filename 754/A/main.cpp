#include <iostream>
#include <vector>
using namespace std;


int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	long s1=0;
	for (int i=0;i<n;++i){
		cin>>v[i];
		s1+=v[i];
	}
	//
	if (v.size()<2){
		cout<<"NO"<<endl;
		return 0;
	}
	int div=0;
	long s0=0;
	while(div!=n-1 && (s0==0|| s1==0)){
		s0+=v[div];
		s1-=v[div];
		++div;
	}
	if (s0!=0 && s1!=0){
		cout<<"YES"<<endl;
		cout<<2<<endl;
		cout<<1<<" "<<div+1<<endl;
		cout<<div+2<<" "<<n<<endl;
	} else {
		cout<<"NO"<<endl;
	}


	return 0;
}
