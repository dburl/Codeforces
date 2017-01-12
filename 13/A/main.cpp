#include <iostream>
#include <vector>

using namespace std;

int main(){
	int a;
	cin>>a;
	//
	int averDiv=0;
	long long averSum=0;
	for (int base=2;base<a;++base){
		++averDiv;
		int num=a;
		//vector<int> inBase;
		//long long sum=0;
		while (num!=0){		
			int rem=num%base;
			averSum+=rem;
			num=num/base;
			//inBase.push_back(rem);
			//cout<<rem;
		}
		//cout<<endl;
	}
	// prepare out
	int upperBound=averDiv;
	for(int i=2;i<=upperBound;++i){
		if (((averDiv%i)==0) && ((averSum%i)==0)){
			averDiv=averDiv/i; averSum=averSum/i;
		}
	}
	cout<<averSum<<"/"<<averDiv<<endl;

	return 0;
}
