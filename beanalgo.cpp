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




ll power(ll powe)
{
	if(powe<=1) return 0;
	else if(powe==1) return 0;
	else
	{
		ll x = power(powe/2);
		x++;
		if(powe%2==1) x++;
		return x;
	}
	

}

int main()
{
	ll t,n;
	scan(t);
	while(t--)
	{
		scan(n);
		
		printf("%lld\n",power(n));
	}

}