#include <iostream>

using namespace std;

int maxim(int a, int b){

if (a>b) return a; else return b;
}

int main(){
	int y=-1,w=-1;
	cin>> y>>w;
	int m= 6-maxim(y,w)+1;
	if (m%6==0) cout << "1/1"<< endl; 
	else if (m%3==0) cout << (m/3)<<"/"<<2<< endl;
	else if (m%2==0) cout << (m/2)<<"/"<<3<< endl;
	else cout << (m)<<"/"<<6<< endl;
	return 0;
}
