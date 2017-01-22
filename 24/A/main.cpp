#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct R{
	int a;
	int b;
	int c;
	};

int main(){
	int n;
	cin>>n;
	vector<R> v(n);
	for (int i=0;i<n;++i){
		cin>>v[i].a>>v[i].b>>v[i].c;
	}
	//
	//one dir
	vector<R> seq1, seq2;
	int cost1=0, cost2=v[0].c;
	seq1.push_back(v[0]);
	for (int i=0;i<n-1;++i){	
		int start=seq1.back().a;
		int dest=seq1.back().b;
		for (int j=0;j<n;++j){
			if (v[j].a==dest){
				seq1.push_back(v[j]);
				cost2+=v[j].c;
				break;			
			} else if (v[j].b==dest && v[j].a!=start){
				v[j].b=v[j].a;
				v[j].a=dest;
				seq1.push_back(v[j]);
				cost1+=v[j].c;
				break;			
			}

		}
	}
	cout<< min(cost1,cost2)<<endl;
	

	return 0;
}
