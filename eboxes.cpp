#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked
char output_buffer[35];
#define ll long long



inline void scan(ll &x){

    register char c = gc();
    x = 0;
    bool neg = false;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=true;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;

}



inline void print(ll n) {
    
    int i=30;
    if(n<0){
        n=-n;
        pc('-');
    }

    do{
        output_buffer[--i]=(n%10)+'0';
        n/=10;
    }while(n);

    do{
        pc(output_buffer[i]);
    }while(++i<30);
    
    pc('\n');

}


int main(){

	ll tes,n,j,k,t,f;

	scan(tes);
	while(tes--){

		scan(n); scan(k); scan(t); scan(f);
		j= (f-n)/(k-1);
		print(n+j*k);
	}

}