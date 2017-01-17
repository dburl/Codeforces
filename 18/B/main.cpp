#include <iostream>

using namespace std;

int main(){
	long long n,d,m,l;
	cin>>n>>d>>m>>l;
	//
	long long x=0;
	long jump=0;
	bool miss=true; 
	long prevB=l;
	do{
	x+=d*(long long)((prevB-x)/d);
	x+=d;
	
	//cout<<"x="<<x<<endl;

	long long full=x/m;
	//cout<<"full="<<full<<endl;
	//cout<<"full*m="<<full*m<<endl;
	//cout<<"(full*m+l)="<<(full*m+l)<<endl;
	//cout<<"(1+full)*(m)="<<(1+full)*(m)<<endl;
	//cout<<"((1+full)*m+l)="<<((1+full)*m+l)<<endl;
	if((full*m<=x) && (x<=(full*m+l)) && (full+1)<=n){
		//cout<<1<<endl;
		prevB =(full*m+l);
		continue;
	} else
	
	if((1+full)*(m)<=x && x<=((1+full)*m+l) && (full+2)<n){
		//cout<<1<<endl;
		prevB =((1+full)*m+l);
		continue;	
	}
	miss=false;
	
	}while(miss);
	cout<<x<<endl;
	return 0;
}
