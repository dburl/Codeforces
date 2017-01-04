#include <iostream>
#include <string>

using namespace std;

unsigned cod0=(unsigned) '_';
unsigned cod1=(unsigned) 'a';
unsigned cod2=(unsigned) 'z';
unsigned cod3=(unsigned) 'A';
unsigned cod4=(unsigned) 'Z';
unsigned cod5=(unsigned) '0';
unsigned cod6=(unsigned) '9';

bool checkC(char c){
	unsigned num =(unsigned)c;
	bool c1 = (cod1<=num) &&(cod2>=num);
	bool c2 = (cod3<=num) &&(cod4>=num);
	bool c3 = (cod0==num) ;
	bool c4 = (cod5<=num) &&(cod6>=num);
	if (c1||c2||c3||c4){
		return true;
	} else {
		return false;
	}
}

bool checkS(string str){
	for(unsigned i=0;i< str.size();++i){
		unsigned num =(unsigned)str[i];
		bool c1 = (cod1<=num) &&(cod2>=num);
		bool c2 = (cod3<=num) &&(cod4>=num);
		bool c3 = (cod0==num) ;
		bool c4 = (cod5<=num) &&(cod6>=num);
		if (!(checkC(str[i]))){
			return false;
		}
	}
	return true;
}

int main(){
	string str;
	cin>> str;
	// allowed set
	
	size_t atIdx=str.find('@');
	bool userCond=checkS(str.substr(atIdx));
	if (atIdx>16 ||atIdx ==0|| !userCond) cout<<"NO"<< endl;

	size_t dotIdx=str.find('.',atIdx);
	size_t prevIdx= atIdx+1;
	while(str.find('.',prevIdx)>0){
		size_t newIdx= str.find('.',prevIdx)>0;
		unsigned len=newIdx-prevIdx;
		string subhost=str.substr(prevIdx,len);
		if (len>16 ||len==0|| !userCond) cout<<"NO"<< endl;
	}
	size_t slashIdx=str.find('/',atIdx);

	cout<< "YES"<<endl;
	
	return 0;
}
