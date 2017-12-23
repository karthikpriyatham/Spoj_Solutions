#include<bits/stdc++.h>
using namespace std;

#define ll  long
#define mod 1000000007
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);

ll res[1000006];
char output_buffer[15];

inline void scan(ll &x){
    register char c = gc();
    x = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    
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

ll scores[100005][6],arr[6]={2,3,6,7,8};

int main(){

	ll n,q;

	for(ll i=0;i<5;i++) scores[0][i]=1;

	for(ll i=1;i<100005;i++){
		for(ll j=0;j<5;j++)
		{

			ll x =(i-arr[j]>=0)?scores[i-arr[j]][j]:0;
			ll y = (j>=1)?scores[i][j-1]:0;
			scores[i][j]=x+y;
		}

	}

	scan(n);
	while(n--){

		scan(q);
		print(scores[q][4]);
		pc('\n');
	}
	
}