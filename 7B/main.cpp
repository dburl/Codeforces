#include<iostream>
#include<vector>
#include <sstream>
#include<iterator>
#include <string>

using namespace std;

int main(){
	int t,m;
	cin>> t>> m;
	vector<string> res(t);

	int blockId=1;
	vector<int> mem(m,0);
	
	for (int i=0;i<t;++i){
		//for (int z=0;z<m;++z){cout<<mem[z];}cout<<endl;
		string command, tmp;
		int num =-1;
		cin>>command;
		if (command!="defragment")  {
			cin >> num;
		}
		//cout << command << num<<endl;
		if (command=="defragment"){
			//cout << "in defrag"<< endl;
			int a =0 , b=0;
			while(b<mem.size()){
				while(mem[a]!=0 && a<mem.size() ){++a;}
				while((mem[b]==0||b<a) && b<mem.size()){++b;}
				while(mem[b]!=0 && b<mem.size()){
					mem[a]=mem[b];
					mem[b]=0;
					++a;++b;
				}
			}	
		}
		//
		
		if (command=="alloc"){
			bool possAlloc=true;
			for (int i=0;i<m;++i){
				possAlloc =true;
				for (int j=i;j<i+num ;++j){
					if(mem[j]!=0){
						possAlloc=false;
						break;
					}			
				}
				if (possAlloc){
					for (int j=i;j<i+num;++j){		
						mem[j]=blockId; 
					}
					//cout<< blockId<<endl;
					stringstream oss;
					oss<<blockId;
					res.push_back(oss.str());
					blockId++;
					break;
				}		
			}
			if (!possAlloc){
				res.push_back("NULL");
				//cout<<"NULL"<<endl;
			}
		}
		if (command=="erase"){
			bool deleted=false;
			for(int i=0;i<m;++i){
				if (mem[i]==num){
					mem[i]=0;
					deleted=true;
				}
			}
			if (!deleted){
				res.push_back("ILLEGAL_ERASE_ARGUMENT");
				//cout<<"ILLEGAL_ERASE_ARGUMENT";	
			}
		}
	}

	for (int i=0;i<t;++i){
		cout<<res[i]<<endl;
	}
	return 0;
}
