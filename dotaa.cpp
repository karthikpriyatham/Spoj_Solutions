#include<bits/stdc++.h>
using namespace std;



#define ll int
#define gc getchar_unlocked


inline void scan(ll &x)
{
    register ll c = gc();
    x = 0;
    ll neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

#define pc putchar_unlocked


int main(){

	int t,n,m,d,i,j;
	scan(t);

	while(t--){

		scan(n);  scan(m); scan(d);
		
		i=0;

		while(n--){
			scan(j);
			i+=((j-1)/d);
		}

		if(i>=m) { pc('Y'); pc('E'); pc('S'); pc('\n'); } 
		else { pc('N'); pc('O'); pc('\n'); }
	

	}


}