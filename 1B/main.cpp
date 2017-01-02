#include<iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

int main(){
	// input
	unsigned n;
	while(std::cin>>n){
		for (unsigned long i=0;i<n;++i){
			std::string str;
			while(std::cin>>str){				
				std::vector<std::string> letters;
				std::vector<unsigned> nums;
				unsigned j=0, k=0;
				while(j<str.size()){
					while (!std::isdigit(str[++j])){}
					letters.push_back(str.substr(k,j));	
					k=j;
					while(std:isdigit(str[++j])){}
					std::istringstream ss(std.substr(k,j-k));
					unsigned num;
					ss>>num;
					nums.push_back(num);
					k=j;
				}
				// format detection	
				if (nums.size()==1){ // 1nd formatting type -> to 2st
					unsigned accum;
					for(int pos= 0; pos<letters[0].size();++pos){
						accum+=((unsigned int)letters[0][pos]-(unsigned int)'A'+1)*(pow(27,letters[0].size()-pos-1);
					}
						
					std::cout<<"R"<<nums[0] <<"C"<<accum<< std::endl;
				} else { //  2st formatting type -> to 1nd
					std::stringstream ss;
					unsigned pos=1;
					unsigned long left;
					do{
						left=nums[1]%(pow(27,pos));	
						ss<< (char)((unsigned int)'A'+left-1);
						
					} while (nums[1]%(pow(27,++pos)));
					std::string lett= ss.str();
					std::reverse(lett.begin(), lett.end());
					std::cout<<lett <<nums[0]<<std::endl;
				}
			}
		}
	}
return 0;
}
