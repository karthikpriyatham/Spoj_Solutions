#include<bits/stdc++.h>
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



char output_buffer[40];
int start;
inline void print(ll n) {
    if(n<0){
        n=-n;
        pc('-');
    }
    
    start=35;
    do{
        output_buffer[--start]=(n%10)+'0';
        n/=10;
    }while(n);
    do{
        pc(output_buffer[start]);
    }while(++start<35);
   

}

long long int dp[36];

int main(){

    ll i,n,t,m;
    dp[0]=1;
    for(i=1;i<36;i++) dp[i]=(dp[i-1]*2);


    scan(t);
    while(t--){
        scan(n);
        if(n==0){
            pc('0'); pc(' '); pc('1'); pc('\n'); continue;
        }
        
        m=n;
        i=0;
        while(n>0){
            if(n&1==1) i++;
            n=n>>1;
        }

        //print(i);
        //pc('\n');
        print(m+1-dp[i]);
        pc(' ');
        print(dp[i]);
        pc('\n');

    }

}
