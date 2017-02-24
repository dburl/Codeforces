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
	getline(cin,s);
	for (int i=s.length()-1;i>=0;--i){
		if (isLetter(s[i])){
			cout<<((isVowel(s[i]))?"YES":"NO")<<endl;
			return 0;
		}
	}

	return 0;
}
