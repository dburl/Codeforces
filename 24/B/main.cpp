#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int points(int pos){
	switch (pos){
	  case	1: return 25;
	  case	2: return 18;
	  case	3: return 15;
	  case	4: return 12;
	  case	5: return 10;
	  case	6: return 8;
	  case	7: return 6;
	  case	8: return 4;
	  case	9: return 2;
	  case	10: return 1;
        	default: return 0;
	}
	return 0;
}

struct Pl{
	string name;
	int point ;
	vector<int> posNum;
};

bool pointComp(Pl a, Pl b){return a.point>b.point;}

vector<Pl> tie1(vector<Pl> v){
	vector<Pl> tmp;
	int p=v[0].point;
	for(int i =0;i<v.size();++i){
		if (v[i].point==p){
			tmp.push_back(v[i]);
		} else {
			break;
		}
	}
	return tmp;
}

bool ordComp(Pl a, Pl b){
	for(int i=0;i<10;++i){
		if (a.posNum[i]>b.posNum[i]){
			return true;
		} else if (a.posNum[i]<b.posNum[i]){return false;}
	}
	return true;
}
//#2
bool ordComp1(Pl a, Pl b){
	return (a.posNum[0]>b.posNum[0]);
}
vector<Pl> tie2(vector<Pl> v){
	vector<Pl> tmp;
	int p=v[0].posNum[0];
	for(int i =0;i<v.size();++i){
		if (v[i].posNum[0]==p){
			tmp.push_back(v[i]);
		} else {
			break;
		}
	}
	return tmp;
}
bool ordComp2(Pl a, Pl b){
	for(int i=1;i<10;++i){
		if (a.posNum[i]>b.posNum[i]){
			return true;
		} else if (a.posNum[i]<b.posNum[i]){return false;}
	}
	return true;
}

int main(){
	int t;
	cin>>t;	
	map<string, Pl> m;
	for (int i=0;i<t;++i){
		int n;
		cin>>n;
		for (int j=0;j<n;j++){
			string name;
			cin>>name;
			m[name].name=name;
			m[name].point+=points(j+1);
			if (m[name].posNum.empty()){
				vector<int> tmp(10);
				m[name].posNum=tmp;
			}
			m[name].posNum[j]+=1;
			//cout<<m[name].name<<":"<<m[name].point;
		}
	}
	//
	vector<Pl> v;
	for(map<string, Pl>::iterator it =m.begin();it!=m.end();++it){
		v.push_back(it->second);
	}
	// sort#1
	sort(v.begin(),v.end(),pointComp);
	vector<Pl> winners = tie1 (v);
	sort(winners.begin(),winners.end(),ordComp);
	cout<<winners[0].name<<endl;
	// sort#2
	sort(v.begin(),v.end(),ordComp1);
	winners = tie2(v);
	sort(winners.begin(),winners.end(),ordComp2);
	cout<<winners[0].name<<endl;

	return 0;
}
