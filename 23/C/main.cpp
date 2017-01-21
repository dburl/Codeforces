#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

struct Box{
	long id;
	long a;
	long o;
};

bool decrA(Box a, Box b){return a.a>b.a;}
bool decrO(Box a, Box b){return a.o>b.o;}

int main(){
	long numTest;
	cin>>numTest;
	vector<string> outT(2*numTest);
	for (long t=0;t<numTest;++t){
		long N;
		cin>>N;
		vector<Box> bv(N);
		long aTotal=0, oTotal=0;
		for (long i=0;i<(2*N-1);++i){
			long a, o;
			cin>>a>>o;
			aTotal+=a; oTotal+=o;
			bv[i].a=a;bv[i].o=o;bv[i].id=i+1;
		}
		//
		sort(bv.begin(),bv.end(),decrA);
		set<set<long> > appBComb;
		for (long i=0;i<(N-1);++i){
			long appCollected=0;
			set<long> tmp;
			for (long j=i;j<i+N;++j){
				appCollected+=bv[j].a;
				tmp.insert(bv[j].id);
			}
			if (appCollected>=(aTotal/2)){
				appBComb.insert(tmp);
			}
		}
		//
		sort(bv.begin(),bv.end(),decrO);
		set<set<long> > orangBComb;
		for (long i=0;i<(N-1);++i){
			long orangCollected=0;
			set<long> tmp;
			for (long j=i;j<i+N;++j){
				orangCollected+=bv[j].o;
				tmp.insert(bv[j].id);
			}
			if (orangCollected>=(oTotal/2)){
				orangBComb.insert(tmp);
			}
		}
		for (set<set<long> >::iterator it=appBComb.begin();it!=appBComb.end();++it){
			if (orangBComb.find(*it)!=orangBComb.end()){ //intersection
				stringstream ss;
				outT[2*t]="YES";
				for (set<long>::iterator ij=(*it).begin();ij!=(*it).end();++ij){
						ss<<*(ij)<<" ";
				}
				outT[2*t+1]=ss.str();
				break;
			}
		}
		if (outT[2*t].empty()){
			outT[2*t]="NO";
		}	
	}	
	//	
	for (long t=0;t<2*numTest;++t){
		cout<<outT[t]<<endl;	
	}	

	return 0;
}
