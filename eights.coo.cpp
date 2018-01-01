#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked


inline void scan(unsigned long long &x){
    register char c = gc();
    x = 0;
    bool neg = false;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=true;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;

}


char output_buffer[76];
inline void print(int n) {
    if(n<0){
        n=-n;
        pc('-');
    }
    int i=76;
    do{
        output_buffer[--i]=(n%10)+'0';
        n/=10;
    }while(n);
    do{
        pc(output_buffer[i]);
    }while(++i<76);
    

}

int main()
{
	unsigned long long t,n,x=192;
	scan(t);
	while(t--){
		scan(n);
		n=192+(250)*(n-1);
		print(n);
		pc('\n');
	}

}