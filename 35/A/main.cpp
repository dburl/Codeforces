#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main(){
	ifstream file("input.txt");
	vector<bool> sh(3,false);
	if (file.is_open()){
		int n;
		file>>n;
		sh[n-1]=true;	
		//cout<<n<<endl;	
		for (int i=0;i<3;++i){
			int a,b;
			file>>a>>b;
			bool tmp=sh[a-1];
			sh[a-1]=sh[b-1];
			sh[b-1]=tmp;
		}	
	}	
	ofstream outf;
	outf.open("output.txt");
	for (int i=0;i<3;++i){
		if (sh[i]){outf<<i+1<<endl;}
	}
	outf.close();
	return 0;
}
