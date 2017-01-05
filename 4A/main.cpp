#include <iostream>

using namespace std;

bool even(unsigned num){if (num%2)return false; else return true;}

int main(){
	unsigned w;
	cin>> w;
	// i- weight of 1st part 
	for (unsigned i=2; i<w; ++i){
		if (even(i)&& even (w-i)){
			cout<<"YES"<< endl;
			return 0;	
		}
	}
	cout<<"NO"<< endl;
	return 0;
}
