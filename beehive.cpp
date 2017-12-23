#include<bits/stdc++.h>
using namespace std;
#define ll long long 
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

int main()
{
	ll n,a;
	while(1)
	{
		scan(n);
		if(n==-1) break;

		n = n-1;
		if(n%3!=0) { printf("N\n");  continue; }
		
		n = n/3;

		//eqn is n^2 + n - c =0
		

		a = sqrt(n);

		if(a*(a+1)==n ) printf("Y\n");
		else printf("N\n");

	}


}