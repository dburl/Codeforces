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
	//cout<< "\t cheking: "<< str<<endl;
	for(unsigned i=0;i< str.size();++i){
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
	bool userCond=checkS(str.substr(0,atIdx));
	if (atIdx>16 ||atIdx ==0|| !userCond) {cout<<"NO"<< endl;return 0;}	

	size_t prevIdx= atIdx+1;
	while(str.find('.',prevIdx)<=str.size()){
		//cout<< "\t\t prevIdx="<< prevIdx<<endl;
		size_t newIdx= str.find('.',prevIdx);
		//cout<< "\t\t newIdx="<< newIdx<<endl;
		unsigned len=newIdx-prevIdx;
		//cout<< "\t\t len="<< len<<endl;
		string subhost=str.substr(prevIdx,len);
		bool userCond=checkS(subhost);
		if (len>16 ||len==0|| !userCond) {cout<<"NO"<< endl;return 0;}	
		prevIdx=newIdx+1;
	}
	size_t slashIdx=str.find('/',atIdx);
	if (slashIdx<=str.size()){
		//cout<< "\t\t slashIdx="<< prevIdx<<endl;
		unsigned len=slashIdx-prevIdx;
		//cout<< "\t\t len="<< len<<endl;
		string subhost=str.substr(prevIdx,len);
		bool userCond=checkS(subhost);
		if (len>16 ||len==0|| !userCond){cout<<"NO"<< endl;return 0;}		
		if ((slashIdx-atIdx-1)>32) {cout<<"NO"<< endl;return 0;}	
	} else{
		unsigned len=str.size()-prevIdx;
		//cout<< "\t\t len="<< len<<endl;
		string subhost=str.substr(prevIdx,len);
		bool userCond=checkS(subhost);
		if (len>16 ||len==0|| !userCond) {cout<<"NO"<< endl;return 0;}	
		if ((str.size()-atIdx-1)>32) {cout<<"NO"<< endl;return 0;}	
	}
	
	//
	if (slashIdx<=str.size()){
		slashIdx++;
		unsigned len=str.size()-slashIdx;
		string subhost=str.substr(slashIdx,len);
		bool userCond=checkS(subhost);
		if (len>16 ||len==0|| !userCond) {cout<<"NO"<< endl;return 0;}	
	} 

	cout<< "YES"<<endl;
	
	return 0;
}
