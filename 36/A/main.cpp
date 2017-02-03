#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream inF("input.txt");
	int n;
	string s;
	if (inF.is_open()){
		inF>>n;
		inF>>s;
	}
//	cout<<"n=="<<n<<endl;
//	cout<<s<<endl;
	//
	vector<int> v;
	int prev=-1;
	for (int i=0;i<s.size();++i){
		if (s[i]=='1' && prev==-1){
			prev=i;
		} else if (s[i]=='1'){
			v.push_back(i-prev);
			prev=i;
		}
	}
	sort (v.begin(), v.end());
	ofstream outF("output.txt");
	for (int i=0;i<(v.size()-1);++i){
		if (v[i]==v[i+1]){
			outF<<"YES"<<endl;
			return 0;
		}
	}
	outF<<"NO"<<endl;

	return 0;
}
