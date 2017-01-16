#include <iostream>
#include <vector>

using namespace std;

bool prime(int a){
	for (int i=2;i<a;++i){
		if (a%i==0){
			return false;		
		}
	}
	return true;
}

vector<int> primes(int a){
	vector<int> tmp;
	for(int i=2;i<=a;++i){
		if (prime(i)){
			tmp.push_back(i);
			//cout<<i<<endl;
		}
	}
	return tmp;
}
bool ifExpress(vector<int>& v, int num){ // if num can be expressed
	for (int i=0;i<v.size()-1;++i){
		if ((v[i]+v[i+1]+1)==num){
			return true;		
		}
	}
	return false;
}

int main(){
	int n,k;
	cin>> n>>k;
	//
	vector<int> v=primes(n);
	int exp=0;
	for (int i=0;i<v.size();++i){
		if (ifExpress(v,v[i])){
			++exp;
		}
	}	
	cout<<((exp>=k)?"YES":"NO")<<endl;
	
	return 0;
}
