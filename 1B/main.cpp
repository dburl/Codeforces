#include<iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <stdlib.h>

int main(){
	// input
	unsigned n;
	std::vector<std::string> strs;
	std::cin>>n;
	for (unsigned i=0;i<n;++i){
		std::string str;
		std::cin>>str;
		strs.push_back(str);
	}			
	// processing
	for(unsigned i=0;i<n;++i){
		std::string str=strs[i];
		std::vector<std::string> letters;
		std::vector<int> nums;
		unsigned j=0, k=0;
		while(j<str.size()){
			while (!std::isdigit(str[++j])){}
			letters.push_back(str.substr(k,j));	
			k=j;
			while(std::isdigit(str[++j])){}
			std::istringstream ss(str.substr(k,j-k));
			int num;
			ss>>num;
			nums.push_back(num);
			k=j;
		}
		// format detection	
		if (nums.size()==1){ // 1nd formatting type -> to 2st
			unsigned accum=0;
			for(int pos= 0; pos<letters[0].size();++pos){
				accum+=((unsigned)letters[0][pos]-(unsigned)'A'+1)*pow(26,letters[0].size()-pos-1);
			}

			std::cout<<"R"<<nums[0] <<"C"<<accum<< std::endl;
		} else { //  2st formatting type -> to 1nd
			std::stringstream ss;
			div_t res;
			res.quot=nums[1];
			do{
				res=div(res.quot,26);
				res.rem=(res.rem)?res.rem:26;	
				ss<< (char)((unsigned)'A'+res.rem-1);

			} while (res.quot&&res.rem);
			std::string lett= ss.str();
			std::reverse(lett.begin(), lett.end());

			std::cout<<lett <<nums[0]<<std::endl;
		}
	}	
	return 0;
}
