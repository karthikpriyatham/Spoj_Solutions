#include<stdio.h>
#define ll  long
#define mod 1000000007
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);

ll res[1000006];
char output_buffer[15];

inline ll scan(ll x){
    register char c = gc();
    x = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    return x;
}


inline void print(ll n) {
    ll i=10;
    
    do{
        output_buffer[--i]=(n%10)+'0';
        n/=10;
    }while(n);
    do{
        pc(output_buffer[i]);
    }while(++i<10);
    pc(' ');

}

int main()
{
 	
     res[0]=1; 
     for(int i=1;i<=1000000;i++)  {
     	res[i]=3*res[i-1] +2;
     	if(res[i]>mod) res[i]%=mod;
	}     	

	ll y,q;
	q=scan(q);
	
	while(q--){
		y=scan(y);
		print(res[y]);
      	pc('\n');

	}


}