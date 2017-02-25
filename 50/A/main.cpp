#include <iostream>

using namespace std;

int main(){
	int M,N;
	cin>>M>>N;
	//
	if (M%2==0 || N%2==0)
		cout<< (M*N)/2<< endl;
	else
		cout<< (M/2)*N +N/2<<endl;

	
	return 0;
}
