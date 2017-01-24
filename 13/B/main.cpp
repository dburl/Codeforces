#include <iostream>

using namespace std;

struct Line{
	int x1;
	int x2;
	int y1;
	int y2;
	};

int find3(const vector<Line>& v){
	for (int i=1;i<3;++i){
		if((v[0].x1==v[i].x1 && v[0].y1==v[i].y1) ||
			(v[0].x2==v[i].x2 && v[0].y2==v[i].y2)){
			if (i==1){return 2;}
			else {return 1;}
		}
	}	
	return 0;
}
bool angle(const vector<Line>& v, int notAngle){
	git	
}

int main(){
	int t=0;
	cin>>t;
	for (int i=0;i<t;++i){
		vector<Line> coord;
		for(int j=0;j<3;++j){
			Line tmp;
			cin>>tmp.x1>>tmp.y1>>tmp.x2>>tmp.y2;
			coord.bush_back(tmp);
		}	
		// check
		int crossNum=find3(coord);
		
		
	}


	return 0;
}
