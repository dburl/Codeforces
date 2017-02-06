#include <iostream>
#include <vector>

using namespace std;

bool fullBlackCol(const vector<string>& v, int k){
	for (int i=0; i<8;++i){
		if (v[i][k]!='B'){
			return false;
		}	
	}
	return  true;
}

bool fullBlackRow(const vector<string>& v, int k){
	string line= v[k];
	for (int i=0; i<8;++i){
		if (line[i]!='B'){
			return false;
		}	
	}
	return  true;
}

int main(){
	vector<string> v(8);
	for(int i=0;i<8; ++i){
		cin>>v[i];
	}
	int blackCol=0, blackRow=0;	
	for(int i=0;i<8;++i){
		if (fullBlackCol(v,i)) {blackCol++;}
		if (fullBlackRow(v,i))	{blackRow++;}
	}
	if (blackCol==8||blackRow==8){cout<<8<< endl; return 0;}
	cout<< blackRow+blackCol<< endl;	

	return 0;
}
