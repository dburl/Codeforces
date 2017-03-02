#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int n;
	cin>>n;
	vector<int> q(3,0);
	for (int i=0;i<n;++i){
		short a;
		cin>>a;
		q[a-1]+=1;
	}
	//
	sort(q.begin(),q.end());
	cout<<q[0]+q[1]<<endl;
	return 0;
}
