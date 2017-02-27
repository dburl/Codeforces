#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stddef.h>
#include <sstream>
#include <cstddef>
#include <string>
using namespace std;

int main(){
	string s, tmp;
	stack<int> st;
	vector<int> v;
	while(cin>>tmp){
		s+=tmp;
	}
	//cout<<s<<endl;
	int i=0;
	size_t posT=0,posTE=0,posC=0;
	while(posT!=string::npos||posTE!=string::npos||posC!=string::npos){
		posT=s.find("<table>",i);
		posTE=s.find("</table>",i);
		posC=s.find("</td>",i);
		
		//cout<<i<<" "<<posT<<" "<<posTE<<" "<<posC<<endl;
		getline(cin,tmp);
		if (posT<posC && posT<posTE){
			st.push(0);
			i=posT+1;
			continue;
		}
		if (posTE<posC && posTE<posT){
			v.push_back(st.top());
			st.pop();
			i=posTE+1;	
			continue;
		}
		if (posC<posTE&&posC<posT){
			st.top()+=1;
			i=posC+1;
			continue;
		}
	}
	sort(v.begin(),v.end());
	stringstream ss;
	for (int i=0;i<v.size();++i){ss<<v[i]<<" ";}
	cout<<ss.str().substr(0,ss.str().size()-1)<<endl;

	return 0;
}
