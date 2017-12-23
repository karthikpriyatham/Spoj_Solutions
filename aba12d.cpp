#include<bits/stdc++.h>
using namespace std;


/**********************************/
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(int d, int n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    int x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}
 
// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(int n, int k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    // Find r such that n = 2^d * r + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
 
    // Iterate given nber of 'k' times
    for (int i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false;
 
    return true;
}




/**************/


/*
	https://oeis.org/A023194
	Naive one wont work , since it takes lot of time 
	10^6 *sqrt(10^6) atmost , which will surely take 10s 



	got new idea from afs spoj

*/

#define ll long long int
#define gc getchar_unlocked
#define max 4400000

ll sums[max],a[max];

inline ll ma(ll a,ll b) { return (a>=b)?a:b; }
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

	ll b =0;
	sums[0]=0; sums[1]=1;

	for(ll p=2; p<=n; p++)
     {
        	// Update all multiples of p
          for (ll i=p*2; i<=n; i += p)
          {
          	sums[i]+=p;
		}
        
     }

     /*for(ll p=1;p<=n;p++) 
     {
     	if(sums[p]==p+1) prime[i]=true;
     	else prime[i]=false;
     }

     printf("%lld\n",b);

     */

}

int main()
{
	ll t;
	sieve(max);

	
	a[0]=a[1]=0;
	for(int i=2;i<=1000000;i++)
	{
		a[i]=0;
		if(sums[sums[i]]==i+1) a[i]=1+a[i-1];
		else a[i]=a[i-1];
	}

	scan(t);
	while(t--)
	{
		ll c,b;
		scan(c);
		scan(b);

		if(c>b) { ll temp=c; c=b; b= temp; }

		//printf("%lld %lld %lld\n",sumDivisorsOfDivisors(2),sumDivisorsOfDivisors(1),sumDivisorsOfDivisors(4));
		if(b<2) { printf("0\n"); continue; }
		else if(b==2) { printf("1\n"); continue; }

		
		printf("%lld\n",a[b]-a[c-1]);

		
	}




}


