#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long 

inline void scanint(ll &x)
{
    register char c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


char output_buffer[35];
inline void print(ll n) {
    if(n<0){
        n=-n;
        pc('-');
    }
    int i=30;
    do{
        output_buffer[--i]=(n%10)+'0';
        n/=10;
    }while(n);
    do{
        pc(output_buffer[i]);
    }while(++i<30);
 

}

inline ll max(ll a,ll b)
{
	if(a>=b) return a;
	return b;
}

int main()
{
	ll n,i,j,t,l,k;
	ll sum,mum;
	l=1;

	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	scanint(t);
	while(t--)
	{
		scanint(n);
		
		if(n==0) {  
		
			pc('C'); pc('a'); pc('s'); pc('e'); pc(' '); print(l); pc(':'); pc(' '); pc('0'); pc('\n');
			l++; continue;  
			
		}
		else if(n==1) 
		{
			scanint(j); pc('C'); pc('a'); pc('s'); pc('e'); pc(' '); print(l); pc(':'); pc(' '); print(j);  pc('\n'); l++; continue;
		}
		
		scanint(i);
		scanint(j);
		sum=max(0,i);
		mum=max(i,j);
		

		for(i=3;i<=n;i++)
		{
			scanint(j);
			k =j+sum;
			sum=mum;
			mum = max(k,mum);
			
		}
		
		
		pc('C'); pc('a'); pc('s'); pc('e'); pc(' '); print(l); pc(':'); pc(' '); print(mum); pc('\n');
		//printf("Case %lld: %lld\n",l,mum);
		l++;
	
	}
	
}