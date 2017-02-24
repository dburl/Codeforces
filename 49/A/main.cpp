#include <iostream>
using namespace std;
#include <set>

static const set<char> vow{'A','E','I','O','U','Y'};

static bool isVowel(char c){
	return ((vow.find(c)!=vow.end())||(vow.find(c-'a'+'A')!=vow.end()));
}
static bool isLetter(char c){
	return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}
int main(){
	string s;
	cin>>s;
	for (int i=s.length()-1;i>=0;--i){
		cout<<s[i]<<endl;
		if (isLetter(s[i])){
			cout<<s[i]<<endl;
			cout<<((isVowel(s[i]))?"YES":"NO")<<endl;
			return 0;
		}
	}

	return 0;
}
