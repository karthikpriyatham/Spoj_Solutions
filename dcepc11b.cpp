// C++ program to comput n! % p using Wilson's Theorem
#include <bits/stdc++.h>
using namespace std;
 

#define ll long
#define gc getchar_unlocked
#define pc putchar_unlocked


inline void scan(ll &x){
    register char c = gc();
    x = 0;
    bool neg = false;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=true;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

char output_buffer[10];
inline void print(ll n) {
    if(n<0){
        n=-n;
        pc('-');
    }
    ll i=10;
    do{
        output_buffer[--i]=(n%10)+'0';
        n/=10;
    }while(n);
    do{
        pc(output_buffer[i]);
    }while(++i<10);

}


// Utility function to do modular exponentiation.
// It returns (x^y) % p
ll power(ll x, ll y,ll p)
{
    ll res = 1;      // Initialize result
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
 
 
// Function to find modular inverse of a under modulo p
// using Fermat's method. Assumption: p is prime
ll modInverse(ll a, ll p)
{
   return power(a, p-2, p);
}
 
// Returns n! % p using Wilson's Theorem
ll modFact(ll n, ll p)
{
    // n! % p is 0 if n >= p
    if (p <= n)
        return 0;
 
    // Initialize result as (p-1)! which is -1 or (p-1)
    ll res = -1,cou=0;
 
    // Multiply modulo inverse of all numbers from (n+1)
    // to p
    for (ll i=p-1; i>n; i--){
       res  = (res * (p-i) ) % p;
       cou++;
    }
    
    if(cou%2==0) { return -1*res; }

    ll j = modInverse(res,p);
    if(j<0) j=j*-1;

    return j;

}

int main(){
    ll t,n,p;
    scan(t);
    while(t--){
        scan(n);
        scan(p);
        if(n>=p) { pc('0'); pc('\n'); continue; }
        print(modFact(n,p));
        pc('\n');
    }
}