#include <iostream>

using namespace std;

int main(){
	int m,d;
	cin>>m>>d;
	//
	int t;
	switch(m){
		case 1: t=31;break;
		case 2:  t=28;break;
		case 3:  t=31;break;
		case 4:  t=30;break;
		case 5: t= 31;break;
		case 6: t= 30;break;
		case 7: t= 31;break;
		case 8: t= 31;break;
		case 9: t= 30;break;
		case 10: t= 31;break;
		case 11: t= 30;break;
		case 12: t= 31;break;
		default: t= 0;
		} ;
	cout<< (d-1+t)/7+(((d-1+t)%7>0)?1:0)<<endl;

	return 0;
}
