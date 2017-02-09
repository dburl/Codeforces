#include <iostream>
#include <set>

using namespace std;

bool ifOn (int x, int y){
	return (x>=0)&& (x<8) && (y>=0) && (y<8);
}

set<pair<int,int> > knight(int x, int y){
	set<pair<int, int> > tmp;
	tmp.insert(make_pair(x,y));
	if (ifOn(x+2,y+1)) 
		tmp.insert(make_pair(x+2,y+1));

	if (ifOn(x+2,y-1)) 
		tmp.insert(make_pair(x+2,y-1));
	if (ifOn(x-2,y+1)) 
		tmp.insert(make_pair(x-2,y+1));

	if (ifOn(x-2,y-1)) 
		tmp.insert(make_pair(x-2,y-1));

	if (ifOn(x-1,y+2)) 
		tmp.insert(make_pair(x-1,y+2));

	if (ifOn(x+1,y+2)) 
		tmp.insert(make_pair(x+1,y+2));

	if (ifOn(x-1,y-2)) 
		tmp.insert(make_pair(x-1,y-2));

	if (ifOn(x+1,y-2)) 
		tmp.insert(make_pair(x+1,y-2));

	return tmp;
}


int main(){
	char a1,a2;
	int y1, y2, x1, x2;
	cin>>a1>>y1;
	cin>>a2>>y2;
	//cout<<x1<<"!"<<y1;
	x1=int('a')-((int) a1);
	x2=int('a')-((int) a2);
	--y1;--y2;
	//
	set<pair<int,int> > s;
	s.insert(make_pair(x1,y1));
	s.insert(make_pair(x2,y2));
	for (int i=0;i<8;++i){
		s.insert(make_pair(x1,i));
		s.insert(make_pair(i,y1));
	}	
	cout<< s.size()<<endl;
	
	set<pair<int,int> > s1=knight(x2,y2);
	set<pair<int,int> > s2=knight(x1,y1);
	s.insert(s1.begin(),s1.end());
	s.insert(s2.begin(),s2.end());
	cout<<s1.size()<<endl;
	cout<<s2.size()<<endl;
	cout<<8*8-s.size()<<endl;

	return 0;
}
