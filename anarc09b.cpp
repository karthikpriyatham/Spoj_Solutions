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

ll gcd(ll a, ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	ll a,b,g,h;
	while(1)
	{
		scan(a); scan(b);
		if(a==0 && b==0) break;
		
		if(a<b) { g = a; a =b; b=g; }
		g = gcd(a,b);

		h = (a*b)/(g*g);
		
		printf("%lld\n",h);


	}


}