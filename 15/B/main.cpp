#include<iostream>
#include<vector>
#include <algorithm>
#include <sstream>
using namespace std;



struct Test {
	long n;
	long m;
	long x1;
	long y1;
	long x2;
	long y2;
	};


int leftV(Test a){
	//cout<<a.m<<" "<<a.y1<<" "<<a.y2<<endl;
	int l=abs(a.y1-a.y2)+1;
	if (l<=(a.m-l)) return 0;
	else return (2*l-a.m);
};

int leftH(Test a){
	//cout<<a.n<<" "<<a.x1<<" "<<a.x2<<endl;
	int l=abs(a.x1-a.x2)+1;
	if (l<=(a.n-l)) return 0;
	else return (2*l-a.n);
};

int left(Test a){
	//cout<<a.n<<" "<<a.x1<<" "<<a.x2<<endl;
	int h=leftH(a);
	int v=leftV(a);
	//cout<< "h="<<h<<"; v="<<v<<endl;
	//return 	h*a.m+v*a.n;//-h*v;
	return 2*(max(h,1)*max(1,v));
};

int main(){
	int t;
	cin>>t;
	vector<Test> v(t);
	vector<int> ss;
	for (int i=0;i<t;++i){
		cin>>v[i].n>>v[i].m>>v[i].x1>>v[i].y1>>v[i].x2>>v[i].y2;
		//cout<<burnedV(v[i])<<endl;
		//cout<<left(v[i])<<endl;
		ss.push_back(left(v[i]));
	}
	//
	for (int i=0;i<t;++i){
	cout<<ss[i]<<endl;
	}

	return 0;
}
