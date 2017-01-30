#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Star{
	int id;
	int y;
	int x;
	int r;
};
bool sort1(Star& a, Star& b){return a.r>b.r;}
bool sort2(Star& a, Star& b){return a.y<b.y;}
bool sort3(Star& a, Star& b){return a.x<b.x;}
bool sort4(Star& a, Star& b){
	if (a.r!=b.r) {
		return a.r<b.r;
	} else if (a.y!=b.y){
		 return a.y<b.y;
	} else {
		return a.x<b.x;
	}
}


int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<string> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	//
	vector<Star> sv;
	for (int i=1;i<n-1;++i){
		for (int j=1;j<m-1;++j){
			for (int r=1;(j-r)>=0 && (j+r)<m 
				&& (i+r)<n && (i-r)>=0;++r) {
				if (v[i][j]=='*'&&v[i-r][j]=='*'&&
						v[i+r][j]=='*'&& 
					v[i][j-r]=='*'&&v[i][j+r]=='*'){
					// star detected
					Star st={0,i,j,r};
					sv.push_back(st);
				}
			}
	
		}
	}
	//cout<< sv.size()<<endl;
	sort(sv.begin(),sv.end(),sort4);
	if (k>sv.size()){
		cout<<"-1"<<endl;
		return 0;
	}
	Star& z=sv[k-1];
	int r=z.r;
	cout<<z.y+1<<" "<<z.x+1<<endl;
	cout<<z.y-r+1<<" "<<z.x+1<<endl;
	cout<<z.y+r+1<<" "<<z.x+1<<endl;
	cout<<z.y+1<<" "<<z.x-r+1<<endl;
	cout<<z.y+1<<" "<<z.x+r+1<<endl;
	
	
	return 0;
}
