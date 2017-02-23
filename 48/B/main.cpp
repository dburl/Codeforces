#include <iostream>
#include <vector>

using namespace std;

int trees(vector<vector<int> >& v, int a, int b, int y, int x){
	int trees=0;
	for (int i=y;i<(y+a);++i){
		for (int j=x;j<(x+b);++j){
			trees+=v[i][j];
		}
	}
	return trees;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > v(n);
	int totTree=0;
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			int tmp;
			cin>>tmp; 
			v[i].push_back(tmp);
			totTree+=tmp;
		}
	}
	int  a, b;
	cin>>a>>b;
	//
	int minTree=totTree;
	for (int i=0;i+a-1<n;++i){
		for (int j=0;j+b-1<m;++j){
			const  int tr=trees(v, a, b, i,j);
			if (tr<minTree){
				minTree=tr;
			}
		}
	}	
	for (int i=0;i+b-1<n;++i){
		for (int j=0;j+a-1<m;++j){
			const int tr=trees(v, b, a, i,j);
			if (tr<minTree){
				minTree=tr;
			}
		}

	}
	cout<<minTree<<endl;
	
	return 0;
}
