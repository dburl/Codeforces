#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<string> m(3);
	for (int i=0;i<3;++i){
		cin>> m[i];		
	}
	//
	for (int i=0;i<3;++i){
	 	for (int j=0;j<3;++j){
			char poitVal=m[i][j];
			int simI= (1-i)+1;
			int simJ= (1-j)+1;
			char simVal=m[simI][simJ];
			if (simVal!=poitVal){
				cout<< "NO"<< endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
