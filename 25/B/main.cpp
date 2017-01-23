#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	//
	string newNum;
	
	for (int i=0;i<str.size();++i){
		newNum.push_back(str[i]);
		if ((i%2>0)&& i<str.size()-2){
			newNum.push_back('-');
		}		

	}
	cout<< newNum<<endl;

	return 0;
}
