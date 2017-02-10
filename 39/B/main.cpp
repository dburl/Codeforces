#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Inc {
	int a;
	int y;
};

bool comp(Inc a, Inc b){return a.a<b.a;}

int main(){
	int n;
	cin>>n;
	vector<Inc> a(n);
	for (int i=0;i<n;++i){
		cin>>a[i].a;
		a[i].y=2001+i;
	}
	//
	sort(a.begin(),a.end(),comp);
	vector<int> years;
	int count=1;
	int year=2000;
	for (int i=0;i<n;++i){
		if ((a[i].a==count) && (a[i].y>year)){
			year=a[i].y;
			years.push_back(year);
			++count; 
		}
	}
	cout<<years.size()<<endl;
	for(int i=0;i<years.size();++i){
		cout<<years[i]<<" ";
	}
	cout<<endl;
		
	return 0;
}
