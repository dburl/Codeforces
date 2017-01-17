#include <iostream>

using namespace std;

int main(){
	int n,d,m,l;
	cin>>n>>d>>m>>l;
	//
	long x=0;
	long jump=0;
	bool miss=true;
	do{
	x+=d;
	++jump;
	//cout<<"x="<<x<<endl;

	long full=x/m;
	//cout<<"full="<<full<<endl;
	//cout<<"full*m="<<full*m<<endl;
	//cout<<"(full*m+l)="<<(full*m+l)<<endl;
	//cout<<"(1+full)*(m)="<<(1+full)*(m)<<endl;
	//cout<<"((1+full)*m+l)="<<((1+full)*m+l)<<endl;
	if((full*m<=x) && (x<=(full*m+l)) && full<=n){
		//cout<<1<<endl;
		continue;
	} else
	
	if((1+full)*(m)<=x && x<=((1+full)*m+l) && full<n){
		//cout<<1<<endl;
		continue;	
	}
	miss=false;
	
	}while(miss);
	cout<<x<<endl;
	return 0;
}
