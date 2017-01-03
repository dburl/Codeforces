#include <iostream>
#include <set>
#include <iterator>
#include <sstream>
#include <vector>
int main(){
	unsigned n;
	std::cin>>n;

	typedef std::vector<std::pair<std::string, std::vector<int> > > NameHist;
	NameHist scores;
	
	int maxScore=-1000001;
	std::set<std::string> winners;

	for (unsigned i=1; i<=n; ++i){
		// get round result
		std::string name;
		int score;
		std::cin>> name>> score;
		// register the score
		int lstScore=0;
		bool updated=false;
		for (NameHist::iterator it=scores.begin();it!=scores.end();++it){
			if (it->first == name){
				lstScore=it->second.back()+score;
				it->second.push_back(lstScore);	
				updated=true;
			} else{
				it->second.push_back(it->second.back());	
			}
		}
		if (!updated){ // new entry
			std::vector<int> v (i,0);
			v.back()=score;
			lstScore=score;
			scores.push_back(std::pair<std::string, std::vector<int> > (name, v));
		}		
		// update winner	
		if (lstScore>maxScore){
			maxScore=lstScore;
			winners.clear();
			winners.insert(name);
		} else if (lstScore==maxScore){
			winners.insert(name);	
		}
	}
	// check who reached the maxScore first
	unsigned earlyStep=1001;
	std::string winner=*winners.begin();
	if (winners.size()>1){
	for(NameHist::const_iterator it=scores.begin();it!=scores.end();++it){
		if (winners.find(it->first)!=winners.end()){
			for (size_t j=0;j<it->second.size();++j){
				if (j<earlyStep&&it->second[j]>=maxScore){
					earlyStep=j;
					winner=it->first;
			}
		}
	}
	}
	}
	std::cout<<winner<<std::endl;

	return 0;
}
