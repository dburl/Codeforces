#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool check(int i, const vector<int>& Xs, const vector<int>& Ys){
	int x=Xs[i], y=Ys[i];
	for (int j=i+2;j<Xs.size();++j){
		int nx=Xs[j], ny=Ys[j];
			//cout<<x<<' '<<y<<endl;
			//cout<<nx<<' '<<ny<<endl;
		if ((abs(nx-x)+abs(ny-y))<2){
			
			return false;
		}
	}
	
	return true;
}

int main(){
	string str;
	cin>> str;
	int x=0, y=0;
	vector<int> Xs,Ys;
	Xs.push_back(x); Ys.push_back(y);
	for (int i=0;i<str.size();++i){
		if (str[i]=='L')	{ --x; Xs.push_back(x); Ys.push_back(y);}
		else if (str[i]=='R')	{++x; Xs.push_back(x);Ys.push_back(y);}
		else if (str[i]=='U')	{++y; Xs.push_back(x); Ys.push_back(y);}
		else 	{--y; Xs.push_back(x); Ys.push_back(y);}
	}
	for (int i=0; i< Xs.size(); ++i){
		if (!check(i,Xs,Ys)){
			cout<< "BUG"<< endl;
			return 0;		
		}	
	}
	cout<< "OK"<< endl;
	
	return 0;
}
