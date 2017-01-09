#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, p1,p2,p3, t1, t2;
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	vector<int> l(n),r(n);
	vector<int> pauses;
	for (int i=0;i<n;++i){
		cin>>l[i]>>r[i];
	}
//	
	//normal
	//cout<< "read"<< endl;
	int p1Total=0;
	int p23Total=0;
	for(int i=0;i<n;++i){
		p1Total+=(r[i]-l[i])*p1;
		//cout<< "(r[i]-l[i])*p1 "<< (r[i]-l[i])*p1<< endl;	
		if (i<n-1){
			int pause= l[i+1]-r[i];
			int p2Cons=0;
			int p3Cons=0;
			
			int moment1=pause-t1;
			int moment2=pause-(t1+t2);
			int moment0=min(pause, t1);
			if (moment1>0){
				if (moment2>0){
					p2Cons+=t2*p2;			
				} else{
					p2Cons+=moment1*p2;
				}
			}
			if (moment2>0){
				p3Cons+=moment2*p3;		
			}
			//cout<< "p2Cons"<< p2Cons<< endl;
			//cout<< "p3Cons"<< p3Cons<< endl;
			p23Total+=p2Cons;
			p23Total+=p3Cons;
			p23Total+=moment0*p1;
		}
	}
	cout<< p1Total+p23Total<< endl;

	return 0;
}
