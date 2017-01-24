#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Cont{
	long box;
	long match;
	};
bool comp(Cont a, Cont b){return a.match>b.match;}

int main(){
	long n;
	int m;
	cin>>n>>m;
	vector<Cont> v(m);
	for (int i=0;i<m;++i){
		cin>> v[i].box>>v[i].match;
	}
	//
	sort(v.begin(),v.end(),comp);
	//for (int i=0;i<m;++i){
	//	cout<< v[i].match<<endl;
	//}
	long leftB=n;
	long long totalMatch=0;
	int i=0;
	while(leftB>0 && i<m){
		for (;i<m;++i){
			if (leftB>=v[i].box){ // steal whole container
				totalMatch+=v[i].box*v[i].match;
				leftB=leftB-v[i].box;
			} else {
				totalMatch+=leftB*v[i].match;
				leftB=0;
				break;
			}
		}
	}
	cout << totalMatch<< endl;




	return 0;
}
