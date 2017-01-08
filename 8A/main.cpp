#include <iostream>
#include <algorithm>
#include<string>

using namespace std;

bool check(const string& path, const string& a, const string& b){
        for (int i=0;i<path.size();++i){
                bool fstPos=true;
                for(int j=0;j<a.size();++j){
                        if ((i+j)>=path.size() || path[i+j]!=a[j]){
                                fstPos=false;
                                break;
                        }
                }
		//cout << "fstPos:"<< fstPos<<endl;
		if (fstPos){
			for(int z=i+a.size();z<path.size();++z){
				bool sndPos=true;
				for(int k=0;k<b.size() ;++k){
					if ((z+k)>=path.size() || path[z+k]!=b[k]){
						sndPos=false;
						break;		
					}
				}	
				if (fstPos&&sndPos){
					return true;
				}	
			}	
		}
	}
	return false;
}


int main(){
        string path;
        cin>> path;
        string a,b;
        cin>>a;
        cin>>b;
        //
	bool oneWay=check(path,a,b);
	reverse(path.begin(), path.end());
	bool backWay=check(path,a,b);

	if (oneWay&&backWay){ cout<<"both"<<endl;}
	else if (oneWay) {cout<<"forward"<<endl;}
	else if (backWay) {cout<<"backward"<<endl;}
	else {cout<<"fantasy"<<endl;}

        return 0;

}
