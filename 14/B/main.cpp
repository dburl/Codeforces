#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	int n, x0;
	cin>>n>> x0;
	vector<int> av(n),bv(n), a,b;
	vector<char> lr;
	set<int> notVisited;
	for(int i=0;i<n;++i){
		cin>>av[i]>>bv[i];
		if ((av[i]>x0) || (bv[i]<x)){
			a.push_back(av[i]); b.push_back(bv[i]);	
			if (av[i]>x0){ lr.push_back('l');}
			else{lr.push_back('r');}
		}

	}
	//
	int mostLeft=x, mostRigh=x;
	for(int i=0;i<a.size();++i){
		if (lr[i]=='l'){ // find the most right segment begin
			if (a[i]>mostLeft) mostLeft=a[i];
		} else{ // find the most left segment finish
			if (b[i]<mostRight) mostRight=b[i];
		}
	}




}
