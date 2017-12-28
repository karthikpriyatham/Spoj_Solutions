#include<bits/stdc++.h>
using namespace std;
#define MAXN   1000001


#define gc getchar_unlocked
#define pc putchar_unlocked


inline void scan(int &x){
    register char c = gc();
    x = 0;
    bool neg = false;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=true;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

char output_buffer[10];
inline void print(int n) {
	if(n<0){
		n=-n;
		pc('-');
	}
	int i=10;
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		pc(output_buffer[i]);
	}while(++i<10);
}

// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[0]=1;
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i+=2)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 



inline int gcd(int u,int v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    if(u<v) { int temp=u; u=v; v=temp; }
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
    		//pc('k');
        v >>= __builtin_ctz(v);
        if (u > v) {
            int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}

inline int primefac(int g){

	int i,j,k=1;
	while(g>1){

		i =spf[g];

		j=0;
		while(g>1 && g%i==0){
			j++;
			g=g/i;
		}

		k*=(j+1);
		//pc('k');

	}

	return k;

}

int main(){

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t,a,b,g;
	scan(t);
	sieve();
	while(t--){
		scan(a);
		scan(b);
		if(a<b){ g=a; a=b; b=g; }
		g = gcd(a,b);
		g=primefac(g);
		print(g);
		pc('\n');
	}
	
}