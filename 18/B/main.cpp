#include <iostream>

using namespace std;

int main(){
	long long n,d,m,l;
	cin>>n>>d>>m>>l;
	//
	if (d==m){cout<< m*n<<endl;return 0;}
	else if((d/m)<1){cout<<(1+m/d)*d<<endl;return 0;}
	else {
		int hop=l/(d%m);
		if (hop>=n){
			cout<<d*(hop+1)<<endl;
			return 0;
		} else{
			cout<<d*(1+(n*m+l)/d)<<endl;
			return 0;
		}
	}
	return 0;
}
