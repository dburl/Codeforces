#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

double x, y;
double n, vb, vs;
vector<double> v;

double dist(int i){
	return sqrt( (v[i]-x)*(v[i]-x)+y*y );
}


int main(){

	cin>> n>>vb>>vs;

	vector<double> byFoot;
	double	minTime = -1;
	int busMinTime=1;

	for (int i=0; i<n;++i){
		double tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	cin>> x>>y;
	byFoot.push_back(dist(0));

	for (int i=1; i<n;++i){
		double a=((double) v[i])/((double) vb);
		double b=dist(i)/((double) vs);

		byFoot.push_back(dist(i));


		if (minTime<0||minTime> (a+b)){
			minTime=a+b;
			busMinTime=i;
		} else if (minTime==(a+b)){
			//cout<<"minTime==(a+b)"<<byFoot[busMinTime]<<endl;
			if (dist(i)<byFoot[busMinTime]){
				//cout<<"busMinTime=i;"<<i<<endl;
				busMinTime=i;			
			}
		}
		//cout<<"minTime "<<  minTime<<endl;
		//cout<<"dist(i)"<< dist(i)<< endl;
		//cout<< busMinTime<<endl;

	}
	cout << busMinTime+1<< endl;

	return 0;
}
