#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	unsigned d, sum;
	cin>> d >> sum;
	vector<unsigned> min , max;
	vector<unsigned> minT , maxT;
	for (unsigned i=0;i<d; ++i){
		unsigned tmpMin, tmpMax;
		cin>> tmpMin >> tmpMax;
		min.push_back(tmpMin);
		max.push_back(tmpMax);

		minT.push_back((i)? minT.back()+tmpMin: tmpMin);
		maxT.push_back((i)? maxT.back()+tmpMax: tmpMax);
	}	
	if ( (minT.back()<=sum)&&(sum<=maxT.back()) ){
		cout<< "YES"<< endl;	
	} else {
		cout<< "NO"<<endl;
		return 0;
	}
	// schedule
	vector<unsigned> schRev;
	for (unsigned i=d-1;i>0;--i){
		//cout<<"1"<< endl;
		for (unsigned j=min[i]; j<=max[i];++j){
			if (  ( (sum-j) >= minT[i-1] ) && ( (sum-j) <= maxT[i-1])  ){ // j fits
				schRev.push_back(j);
				sum=sum-j; 
				//cout<<"Work at day"<< i<<" during "<< j<< "hours"<< endl;
				break;
			}
			
		}
	}
	schRev.push_back(sum);
	//cout<<"Sch computed "<< endl;	
	std::reverse(schRev.begin(),schRev.end());
	for(unsigned i=0;i<d;++i){
		cout<<schRev[i]<<" ";
	}
	cout<< endl;

	return 0;
}
