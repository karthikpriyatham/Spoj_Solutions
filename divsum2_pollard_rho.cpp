
#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <cmath>
using namespace std;

#define sq(x) ((x)*(x))
#define i64 unsigned long long
#define MAX 100000000
#define mux 1000000
#define LMT 10000


#define gc getchar_unlocked


inline void scan(i64 &x)
{
    register char c = gc();
    x = 0;
    bool neg = false;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=true;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}


#define pc putchar_unlocked

char output_buffer[35];
inline void print(i64 n) {
    if(n<0){
        n=-n;
        pc('-');
    }
    int i=25;
    do{
        output_buffer[--i]=(n%10)+'0';
        n/=10;
    }while(n);
    do{
        pc(output_buffer[i]);
    }while(++i<25);
    pc('\n');

}

bool flag[MAX/64];
unsigned primes[5761460], total;
long sums[mux];

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
    unsigned i, j, k,s;

    flag[0]=flag[1]=false;
    sums[1] = 1; sums[0]=0;
    for(j = 2; j <max; j++){
        sums[j] = 1 + j;
        flag[i]=true;
    }

    for(k = 2; k*k <mux; k++){
            j=k*k;
            sums[j]+=k;
            j+=k;
            s=k+(k + 1);
            while (j<=mux){
            
                sums[j] += s;
                j+=k;
                s++; // s equals k + j / k
        }

    }

    flag[0]|=0;
    for(i=3;i<LMT;i+=2){
        if(!chkC(i))
            for(j=i*i,k=i<<1;j<MAX;j+=k)
                setC(j);
    }

    primes[(j=0)++] = 2;
    for(i=3;i<MAX;i+=2)
        if(!chkC(i))
            primes[j++] = i;
    total = j;
}

i64 power(i64 n, unsigned p)
{
    i64 x=1, y=n;
    while(p > 0)
    {
        if(p&1) x *= y;
        y *= y;
        p >>= 1;
    }
    return x;
}

inline void update(i64 &phi1, i64 n, unsigned p)
{
    if(p==1) phi1 *= (n+1);
    else phi1 *= ((power(n,p+1)-1)/(n-1));
}

void factor(i64 n, i64 &phi1)
{
    unsigned i, v;
    i64 t;
    phi1 = 1;
    for(i=0, t=primes[i]; i<total && t*t <= n; t = primes[++i])
    {
        if(n % t == 0)
        {
            v = 0;
            while(n % t == 0)
            {
                v++;
                n /= t;
            }
            update(phi1, primes[i], v);
        }
    
        if(n<mux){
            phi1 = phi1*sums[n];
            return;
        }    

    }
    
    if(n>1) update(phi1, n, 1);


}

int main()
{
    i64 t, x;
    i64 n, phi1;
    sieve();
    scan(t);
    for(x=1; x<=t; x++)
    {
        scan(n);
        factor(n, phi1);
        print(phi1-n);
    }
    return 0;
}
