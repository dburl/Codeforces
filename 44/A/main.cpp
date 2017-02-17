#include <iostream>
#include <set>

using namespace std;

struct L{
	string c;
	string s;
	const bool operator <(const L& b) const {
		if (s!=b.s){
			return s<b.s;
		} else {
			return c<b.c;
		}
	}
};

int main(){
	int n;
	cin>>n;
	set<L> s;
	for (int i=0;i<n;++i){
		L tmp;
		cin>>tmp.s>>tmp.c;
		s.insert(tmp);
	}
	cout<<s.size()<<endl;




	return 0;
}
