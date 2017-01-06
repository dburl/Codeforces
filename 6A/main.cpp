#include<iostream>
#include <vector>

using namespace std;

int min3(int a,int b){
	if (a>=b){
		return a-b;		
	} else{
		return b-a;
	}
}

int max3(int a,int b){return a+b;}


int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	vector<int> v;
	v.push_back(a);	v.push_back(b); v.push_back(c);	v.push_back(d);
	for (int i=0; i<4;++i){
		int max=max3(v[i%4],v[(i+1)%4]);
		int min=min3(v[i%4],v[(i+1)%4]);
		int c=v[(i+2)%4];
		if (c > min &&c<max){cout<<"TRIANGLE"<<endl; return 0;}
	}
	for (int i=0; i<4;++i){
		int max=max3(v[i%4],v[(i+1)%4]);
		int min=min3(v[i%4],v[(i+1)%4]);
		int c=v[(i+2)%4];
		if (c==min||c==max){cout<<"SEGMENT"<<endl; return 0;}
	}
	cout<<"IMPOSSIBLE"<<endl; return 0;
}
