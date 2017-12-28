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

char output_buffer[15];
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
    pc('\n');

}


ll sums[500005];

inline void sieve(ll n){

	int j,k,s;
	sums[1] = 1; sums[0]=0;
	for(j = 2; j <= n; j++)
    		sums[j] = 1 + j;

	for(k = 2; k*k <= n; k++){
		j=k*k;
    		sums[j]+=k;
    		j+=k;
    		s=k+(k + 1);
    		while (j<=n){
			
			sums[j] += s;
        		j+=k;
        		s++; // s equals k + j / k
 		}

 	}

}

int main(){

	ll t,n;
	sieve(500005);
	scan(t);
	while(t--){

		scan(n);
		print(sums[n]-n);
	}

}