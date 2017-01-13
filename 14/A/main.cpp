#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<string> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	// top->down
	int veryTop=-1;
	for (int i=0;i<n;++i){
	// if all in row are '.' veryTop=i
		bool metStar=false;
		for (int j=0;j<m;++j){
			if(v[i][j]=='*'){
				metStar=true;
				break;		
			}
		}
		if (!metStar){
			veryTop=i;
		} else {
			break;	
		}
	}
	//cout<<veryTop<< endl;
	// botton-> up
	int veryBottom=n;
	for (int i=n-1;i>=0;--i){
	// if all in row are '.' veryTop=i
		bool metStar=false;
		for (int j=0;j<m;++j){
			if(v[i][j]=='*'){
				metStar=true;
				break;		
			}
		}
		if (!metStar){
			veryBottom=i;
		} else {
			break;	
		}
	}
	//cout<<veryBottom<< endl;
	// left->right
	int veryLeft=-1;
	for (int j=0;j<m;++j){
	// if all in row are '.' veryTop=i
		bool metStar=false;
		for (int i=0;i<n;++i){
			if(v[i][j]=='*'){
				metStar=true;
				break;		
			}
		}
		if (!metStar){
			veryLeft=j;
		} else {
			break;	
		}
	}
	//cout<<veryLeft<< endl;
	// right->left
	int veryRight=m;
	for (int j=m-1;j>=0;--j){
	// if all in row are '.' veryTop=i
		bool metStar=false;
		for (int i=0;i<n;++i){
			if(v[i][j]=='*'){
				metStar=true;
				break;		
			}
		}
		if (!metStar){
			veryRight=j;
		} else {
			break;	
		}
	}
	//cout<<veryRight<< endl;
	for (int i=veryTop+1;i<veryBottom;++i){
		for(int j=veryLeft+1;j<veryRight;++j){
			cout<<v[i][j];	
		}
			cout<<endl;
	}
	
	return 0;
}
