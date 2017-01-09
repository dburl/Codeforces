#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;


int xc, yc;
int n,k;

int row=-1 , leftSeat=-1, rightSeat=-1;

int costOne(const int x, const int y){
	return abs(x-xc)+abs(y-yc);
}

int costAll(vector<vector<int> >& z,int x, int y, int m){
	int totalCost;
	for (int i=0;i<m;++i){
		if ( (y+m-1)>=k|| z[x][y+i]!=0){ //occuppied
			return -1;
		} else{
			totalCost+=costOne(x,y+i);
		}
	}
	return totalCost;
}

bool place( vector<vector<int> >& z, int m){
	int minCost=1000000000;
	bool possible=false;
	//int row=-1  leftSeat=-1, rightSeat=-1;
	for (int i=0;i<k;++i){
		for(int j=0;j<k;++j){
			int cost=costAll(z, i, j, m);
			if (cost>=0 && minCost>cost){
				row=i; leftSeat=j; rightSeat=j+m;
				possible=true;
			} //else if (minCost==cost){
			  //	nRow=i+1; nLeftSeat=j+1; nRightSeat=j+m+1;
			 //}
		}
	}
	return possible;
}

void occupy( vector<vector<int> >& z, int m){
	for (int i=0;i<m;++i){
		z[row][leftSeat+i]=1;
	}
}
	

int main(){

	cin>>n>>k;

	xc= ceil(k/2);	yc= ceil(k/2);

	vector<vector<int> > z(k);
	for (int i=0;i<k;++i){
		vector<int> tmp(k,0);
		z.push_back(tmp);
	}
		

	vector<int> v(n,0);
	for (int i=0;i<n;++i){
		cin>>v[i];
	}
	//
	cout<<"read"<<endl;
	stringstream ss;
	for (int i=0;i<n;++i){
		int m=v[i];
		bool poss=place(z, m);
		if (poss){ss<<row+1<<" "<<(leftSeat+1)<<" "<<rightSeat+m+1<< endl;}
		else {ss<<"-1"<<endl;}
		if (poss) {occupy(z, m);}
		cout<< "allocated"<<endl;
	}
	cout<<ss;

	return 0;
}
