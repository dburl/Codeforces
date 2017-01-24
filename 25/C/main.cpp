#include <iostream>
#include<vector>
#include <stack>

using namespace std;

struct R{
	int a;
	int b;
	int c;
};

void update (vector<vector<int> >& v, stack<R>& u){
	if(u.empty()){ return;}
		R r= u.top(); u.pop();
		int row=r.a;//city a
		int col=r.b;//city b
		if (v[row][col]>r.c){
			v[row][col]=r.c;
			v[col][row]=r.c;
		}
	
		for (int i=0;i<v.size();++i){
			if (v[row][i]>(v[col][i]+v[row][col])){
				R tmp={row, i,v[col][i]+v[row][col]};
				u.push(tmp);
			}
			if (v[i][col]>(v[i][row]+v[row][col])){
				R tmp={col, i,v[i][row]+v[row][col]};
				u.push(tmp);
			}
		}
		update(v,u);
	
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
	for (int i=0;i<k;++i){
		R r;
		cin>>r.a>>r.b>>r.c;r.a-=1;r.b-=1;
		stack<R> tmp;
		tmp.push(r);
		update(v,tmp);
		cout<<dSum(v)<<" ";
	}
	cout<<endl;

	return 0;
}
