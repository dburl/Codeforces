#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x=0, y=0;
vector<int> Xs, Ys;

int sqr(int a){return abs(a)*abs(a);}

int time(int i, int j){
	if (i==-1)
		return	sqr(Xs[i]-x)+sqr(Ys[i]-y);
	else
		return	sqr(Xs[i]-Xs[j])+sqr(Ys[i]-Ys[j]);
}

struct Poss{
	int fst;
	int snd;
	double cost;
	int dist;
	bool operator <(const Poss& b){return this->cost<b.cost;}
	
};

int main(){
	

	cin>>x>>y;
	int n=0;
	cin>> n;

	for (int i=0;i<n;++i){
		cin>>Xs[i]>>Ys[i];
	}
	int left=n;
	vector<int> seq;seq.push_back(0);

	int totalTime=0;
	while(left!=0){
		vector<Poss> v;
		for (int i=0;i<n;++i){
			if (find(seq.begin(),seq.end(), i+1)==seq.end()){
				Poss tmp;	
				tmp.fst=i+1;
				tmp.snd=-1;
				tmp.cost=time(-1,i);
				tmp.dist=2*time(-1,i);
				v.push_back(tmp);
				for(int j=0;j<n;++j){
					if (find(seq.begin(),seq.end(), j+1)==seq.end() && j!=i){
						tmp.snd=j+1;
						tmp.cost=tmp.cost+time(i,j);
						tmp.cost=tmp.cost/2;
						tmp.dist=tmp.dist+2*time(i,j);
						v.push_back(tmp);
					}
				}
				
			} 
		}
		sort(v.begin(), v.end());
		Poss c= v[0];
		
		seq.push_back(c.fst);
		--left;
		if (c.snd>0){
			seq.push_back(c.snd);
			--left;
		}
		seq.push_back(0);
		totalTime+=c.dist;
			
	}
	cout<<totalTime<<endl;
	for(int i=0;i<seq.size();++i){
		cout<<seq[i]<<" ";
	}
	cout<<endl;

	return 0;
}
