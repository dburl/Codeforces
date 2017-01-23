#include <iostream>
#include<vector>

using namespace std;

struct R{
	int a;
	int b;
	int c;
};

void update (vector<vector<int> >& v, R r){
	int row=r.a-1;//city a
	int col=r.b-1;//city b
	if (v[row][col]>r.c){
		v[row][col]=r.c;
		v[col][row]=r.c;
	}
	for (int i=0;i<v.size();++i){
		if (v[row][i]>(v[col][i]+v[row][col])){
			v[row][i]=(v[col][i]+v[row][col]);
			v[i][row]=(v[col][i]+v[row][col]);
		}
		if (v[i][col]>(v[i][row]+v[row][col])){
			v[i][col]=(v[i][row]+v[row][col]);
			v[col][i]=(v[i][row]+v[row][col]);
		}
	}
}

long dSum(vector<vector<int> >& v){
	long sum=0;
	for (int i=0;i<v.size();++i){
		for (int j=i+1;j<v.size();++j){
			sum+=v[i][j];
		}
	}
	return sum;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int> > v(n);
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			int tmp;
			cin>>tmp;
			v[i].push_back(tmp);
		}
	}
	int k;
	cin>>k;	
	vector<R> nr(k);
	for (int i=0;i<k;++i){
		cin>>nr[i].a>>nr[i].b>>nr[i].c;
	}
	//
	for (int i=0;i<k;++i){
		update(v,nr[i]);
		cout<<dSum(v)<<" ";
	}
	cout<<endl;

	return 0;
}
