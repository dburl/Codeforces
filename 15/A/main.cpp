#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



struct House{
	int x;
	float a;
	};

int comp(House a , House b){return a.x<b.x;}

int main(){
	int n, t;
	cin>>n>>t;
	vector<House> h(n);
	for (int i=0;i<n;++i){
		cin>>h[i].x>>h[i].a;
		h[i].a=h[i].a/(float)2;
	}
	//
	sort (h.begin(), h.end(), comp);

	int poss=2;	
	for (int i=0;i<n-1;++i){
		if ((h[i+1].x-h[i+1].a- h[i].x-h[i].a)==t){
			poss++;
		}
		if ((h[i+1].x-h[i+1].a- h[i].x-h[i].a)>t){
			poss+=2;
		}
	}
	cout<< poss<< endl;

	return 0;
}
