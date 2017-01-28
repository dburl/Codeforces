#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<list<int> > vl;
	list<int> dummy;
	vl.push_back(dummy);
	map<int, int > m; // if negativ then front
	for (int i=0;i<n;++i){
		int a,b ;
		cin >> a>>b;
		if (m.find(a)!=m.end()){
			list<int>& l=vl[abs(m[a])];
			if (m[a]>0){ l.push_back(b);} else {l.push_front(b);}
			m[b]=m[a]; m.erase(a);
		} else if (m.find(b)!=m.end()){
			list<int>& l=vl[abs(m[b])];
			if (m[b]>0){l.push_back(a);} else {l.push_front(a);}
			m[a]=m[b]; m.erase(b);
		} else{ 
			list<int> tmp;
			tmp.push_back(a); tmp.push_back(b);
			vl.push_back(tmp);
			m[a]=-(vl.size()-1); m[b]=vl.size()-1;
		}
	}
	//
	for (int i=0;i<vl.size();++i){
		list<int>& l1=vl[i];
		for (int j=i+1;j<vl.size();++j){
			list<int>& l2=vl[j];
			if (l1.front()==l2.front()){
				l2.reverse();
				l2.insert(l2.end(),++l1.begin(),l1.end());
			} else if (l1.back()==l2.front()){
				l1.reverse(); l2.reverse(); 
				l2.insert(l2.end(),++l1.begin(),l1.end());
			} else if (l1.front()=l2.back()){
				l2.insert(l2.end(),++l1.begin(),l1.end());
			} else if (l1.back()==l2.back()){
				l1.reverse();
				l2.insert(l2.end(),++l1.begin(),l2.end());
			}
			
		}
	}
	for (list<int>::const_iterator it=vl.back().begin();it!=vl.back().end();++it){
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}
