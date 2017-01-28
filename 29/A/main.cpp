#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Cam{
	int x;
	int d;

};

int main(){
	int n;
	cin>>n;
	vector<Cam> v(n);
	map<int, vector<int> > m; // x-> IDs
	bool res=false;
	for (int i=0;i<n;++i){
		cin>>v[i].x>>v[i].d;
		m[v[i].x].push_back(i);

		if (!res && !m[v[i].x+v[i].d].empty()){
			vector<int>& targets=m[v[i].x+v[i].d];
			for (int j=0;j<targets.size();++j){
				if ((v[targets[j]].x+v[targets[j]].d)==v[i].x){
					res=true;
				}
			}
		}
	}
	//
	cout<<((res)?"YES":"NO")<<endl;

	return 0;
}
