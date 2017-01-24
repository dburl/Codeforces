#include <iostream>

using namespace std;

long long a,b,x,y;

double bnF(double i){
	return i*((double) y)/((double) x);
}

double anF(double i){
	return i*((double) x)/((double) y);
}

int main(){
	cin>>a>>b>>x>>y;
	// 
	double an1,bn1;
	if (b<bnF(a)){
		an1=anF(b);
		bn1=b;	
	} else if (b>=bnF(a)) {
		an1=a;
		bn1=bnF(a);
	}
	long long an1I,bn1I, S1;
	an1I=(long long) an1;
	bn1I=(long long) bn1;
	S1=an1I*bn1I;

	double an2,bn2;
	if (a<bnF(b)){
		an2=anF(a);
		bn2=a;	
	} else if (b>=bnF(b)) {
		an2=b;
		bn2=bnF(b);
	}
	long long an2I,bn2I, S2;
	an2I=(long long) an2;
	bn2I=(long long) bn2;
	S2=an2I*bn2I;
	if (S1<=0 && S2<=0){
		cout<<"0 0"<<endl;
	} else if (S1>S2){
		cout<<an1I<<" "<<bn1I<<endl;
	} else{
		cout<<bn2I<<" "<<an2I<<endl;
	}

	return 0;
}
