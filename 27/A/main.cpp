#include <iostream>
#include <set>

using namespace std;

int main(){
	int n;
	cin>>n;
	set<int> s;
	int maxV=0;
	for(int i=0;i<n;++i){
		int tmp;
		cin>>tmp;
		s.insert(tmp);
		if (tmp>maxV){
			maxV=tmp;
		}
	}
	//cout<<"M="<<maxV<<endl;
	for (int i=1;i<(maxV+2);++i){
		if (s.find(i)==s.end()){
			cout<<i<<endl;
			return 0;
		}
	}
		


	return 0;
}
