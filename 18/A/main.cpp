#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

bool degenerate(const vector<long>& x, const vector<long>& y){
	return (y[1]-y[2])*(x[0]-x[1])== (y[0]-y[1])*(x[1]-x[2]);
}

bool prob(long a, long b, long c){
	return (a+b)==c || (c+b)==a || (a+c)==b;
}

bool right(const vector<long>& x, const vector<long>& y){
	long d1= ( (x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]) );
	long d2= ((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]));
	long d3= ((x[2]-x[0])*(x[2]-x[0])+(y[2]-y[0])*(y[2]-y[0]));
	return prob(d1,d2,d3);
}
bool almostRigth(const vector<long>& x, const vector<long>& y){
	vector<vector<long> > xxx;
	vector<vector<long> > yyy;
	for (int i=0;i<3;++i){
		vector<long> tmpXP=x;
		vector<long> tmpXM=x;
		vector<long> tmpYP=y;
		vector<long> tmpYM=y;
		//
		tmpXP[i]+=1; xxx.push_back(tmpXP); yyy.push_back(y);
		tmpXM[i]-=1; xxx.push_back(tmpXM); yyy.push_back(y);
		tmpYP[i]+=1; xxx.push_back(x); yyy.push_back(tmpYP);
		tmpYM[i]-=1; xxx.push_back(x); yyy.push_back(tmpYM);
	}
	for (int i=0;i<xxx.size();++i){
		if (right(xxx[i],yyy[i])&& !degenerate(xxx[i],yyy[i])){
			//for (int j=0;j<3;++i){
			//cout<< xxx[i][j]<<" "<<yyy[i][j]<<endl;
			//}
			return true;	
		}	
	}
	return false;
}




int  main(){
	vector<long> x(3),y(3);
	cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];
	//
	if (right(x,y)){
		cout<<"RIGHT"<<endl;
		return 0;	
	} else	if (almostRigth(x,y)) {
		cout<<"ALMOST"<<endl; return 0;
	} else {cout<<"NEITHER"<<endl;}
	
	return 0;
}
