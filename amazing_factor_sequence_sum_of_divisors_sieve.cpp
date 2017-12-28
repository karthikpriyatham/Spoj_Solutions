#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define gc getchar_unlocked
ll sums[1000006];
bool prime[1000006];


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



void sieve(ll n){

	for(ll p=2;p<=n;p++) { sums[p]=1; }

	sums[0]=sums[1]=0;

	for(ll p=2; p<=n; p++)
     {
        	// Update all multiples of p
          for (ll i=p*2; i<=n; i += p)
          {
          	sums[i]+=p;
		}
        
     }
 
 	
     // Print all prime numbers
     for (ll p=2; p<=n; p++)
     {
     	//if(prime[p]==false) sums[p]-=p; 
     	sums[p] += sums[p-1];
     }


}




int main()
{
	ll t,n;

	sieve(1000001);
	
	

	scan(t);
	
	while(t--)
	{
		scan(n);
		printf("%lld\n",sums[n]);
	}


	
}