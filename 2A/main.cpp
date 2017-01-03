#include <iostream>
#include <map>
#include <iterator>
#include <sstream>

int main(){
	unsigned n;
	std::cin>>n;
	std::map<std::string, int> scores;
	
	int maxScore=-1000001;
	std::string firstGained;

	for (unsigned i=1; i<=n; ++i){
		// get round result
		std::string name;
		int score;
		std::cin>> name>> score;
		// register the score

		std::map<std::string,int>::iterator it= scores.find(name);
		if (it!=scores.end()){
			it->second+=score;
		} else{
			scores[name]=score;
		}
		// update winner	
		if (scores[name]>maxScore){
			maxScore=scores[name];
			firstGained=name;
		}	
	}
	std::cout<<firstGained<<std::endl;

	return 0;
}
