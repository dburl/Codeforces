#include <iostream>
#include <set>
using namespace std;

int main(){
	int n;
	cin>>n;
	set<int> s;
	s.insert(1);
	int pos=0;
	int  k=1;
	for (int i=0;i<(n-1);++i){
		pos+=k;
		k+=1;
		pos=pos%n;
		cout<<pos+1<<" ";
	}
	cout<<endl;
	
	return 0;
}
