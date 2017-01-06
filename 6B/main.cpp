#include <iostream>
#include <vector>

using namespace std;

int tables(const vector<vector<char> >& vv, int a, int b, int i, int j){
	int num=0;
	if(i>0){ //check up
		if (vv[i-1][j]!='.'){++num;}			
		}
	if (i<a-1){// check bott
		if (vv[i+1][j]!='.'){++num;}	
	}
	
	if (j<b-1){//check right
		if (vv[i][j+1]!='.'){++num;}	
	}
	if (j>0){// jeck left
		if (vv[i][j-1]!='.'){++num;}
	}
	return num;
}


int main(){
	int a, b;
	char c;
	cin>> a>>b>>c;
	vector<vector<char> > vv(a);
	for (int i=0;i<a;++i){
		string str;
		cin>>str;
		for (int j=0;j<b;++j){
			vv[i].push_back(str[j]);	
		}
	}
	for (int i=0;i<a;++i){
		for(int j=0;j<b;++j){
			if(vv[i][j]==c){ //president
				cout<< tables(vv,a,b,i,j)<< endl;
				return 0;
			}		
		}
	}
	cout<<"0"<< endl;

	return 0;
}


