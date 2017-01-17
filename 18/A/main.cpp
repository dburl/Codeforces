#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;


bool prob(float a, float b, float c){
	return a*a+b*b==c*c || c*c+b*b==a*a || a*a+c*c==b*b;
}

bool right(vector<int>& x, vector<int>& y){
	float d1= sqrt( (x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]) );
	float d2= sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]));
	float d3= sqrt((x[2]-x[0])*(x[2]-x[0])+(y[2]-y[0])*(y[2]-y[0]));
	return prob(d1,d2,d3);
}
bool almostRigth(vector<int>& x, vector<int>& y){
	vector<vector<int> > xxx;
	vector<vector<int> > yyy;
	for (int i=0;i<3;++i){
		vector<int> tmpXP=x;
		vector<int> tmpXM=x;
		vector<int> tmpYP=y;
		vector<int> tmpYM=y;
		//
		tmpXP[i]+=1; xxx.push_back(tmpXP); yyy.push_back(y);
		tmpXM[i]-=1; xxx.push_back(tmpXM); yyy.push_back(y);
		tmpYP[i]+=1; xxx.push_back(x); yyy.push_back(tmpYP);
		tmpYM[i]-=1; xxx.push_back(x); yyy.push_back(tmpYM);
	}
	for (int i=0;i<xxx.size();++i){
		if (right(xxx[i],yyy[i])){
			cout<<"ALMOST"<<endl;
			return true;	
		}	
	}
	return false;
}




int  main(){
	vector<int> x(3),y(3);
	cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];
	//
	if (right(x,y)){
		cout<<"RIGHT"<<endl;
		return 0;	
	}
	if (!almostRigth(x,y)) {cout<<"NEITHER"<<endl;}
	


	return 0;
}
