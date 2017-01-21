#include<iostream>
#include <string>

using namespace std;

int main(){
	string str;
	cin>>str;
	//
	int lenMax=0;
	string strMax="";
	for (int i=0;i<str.size()-1;++i){ // starting point
		for(int l=1;l<=str.size()-i;++l){
			string sub=str.substr(i,l);
			//cout<<l<<": "<<sub<<endl;
			size_t posSec=str.find(sub,i+1);
			if (posSec!=string::npos && (l>lenMax)){
				lenMax=l;
				strMax=sub;		
			}
		}
	}
	cout<<lenMax<<endl;

	return 0;
}
