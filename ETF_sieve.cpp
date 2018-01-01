#include<bits/stdc++.h>
using namespace std;

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



char output_buffer[15];
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
    pc('\n');

}

int primes[800000],l=0;
bool prime[1000005];

inline void sieve(int n){
	
	for(int i=0;i<=n;i++) prime[i]=true;
	prime[0]=false; prime[1]=false;
	for(int i=4;i<=n;i+=2) prime[i]=false;

	for(int i=3;i*i<=n;i+=5){
		if(prime[i]==true){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=false;
			}
		}
		
	}
	
	l=0;
	for(int i=2;i<=n;i++){
		if(prime[i]==true) primes[l++]=i;
	}
	
	
} 

int fi(int n) {    
	
		int result = n;          
		for(int i=0;primes[i]*primes[i] <= n;i++) {            
			if (n % primes[i] == 0) result -= result / primes[i];            
			while (n>0 && n % primes[i] == 0) n /= primes[i];          
		}         
		
		if (n > 1) result -= result / n;          
		return result;        
}   

int main()
{
	int t,n;
	sieve(1000000);
	scan(t);
	while(t--)
     {
    	scan(n);
    	print(fi(n));
	}
}