#include <iostream>
#include <map>
#include <iterator>
#include <sstream>
#include <vector>

int main(){
	unsigned n;
	std::cin>>n;

	std::vector<std::string> roundName;
	std::vector<int> roundScore;
	
	typedef std::map<std::string, int> Name2Score;
	Name2Score scores;


	int maxScore=-1000001;

	for (unsigned i=0; i<n; ++i){
		// get round result
		std::string name;
		int score;
		std::cin>> name>> score;
		roundName.push_back(name);
		roundScore.push_back(score);
		Name2Score::iterator it= scores.find(name);

		int newScore;
		if (it!=scores.end()){
			newScore= it->second+ score;
			it->second= newScore;	
		} else{
			newScore=score;
			scores[name]=newScore;
		}
		
		if (newScore>maxScore){
			maxScore=newScore;
		}
	}
	for(Name2Score::iterator it=scores.begin();it!=scores.end();++it){
		it->second =0;
	}
	
	for (unsigned i=0;i<n;++i){
		scores[roundName[i]]+=roundScore[i];
		if ((scores[roundName[i]])>=maxScore){
			std::cout<<roundName[i]<<std::endl;
			return 0;
		}
	}
	return 0;
}
