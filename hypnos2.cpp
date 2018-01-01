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



char output_buffer[80];
int start;
inline void print(ll n) {
    if(n<0){
        n=-n;
        pc('-');
    }
    
    start=75;
    do{
        output_buffer[--start]=(n%10)+'0';
        n/=10;
    }while(n);
    do{
        pc(output_buffer[start]);
    }while(++start<75);
   
    pc('\n');
}


inline ll dec(ll n){
    ll j=0,k;
    while(n>0){
        k= (n%10);
        j+=(k*k);
        n=n/10;
    }
    return j;
}

int main()
{

    
    ll t,n,m;
    scan(t);

    for(m=0;m<t;m++){

        scan(n);
        

        if(n==1){ pc('0'); pc('\n');  continue; }
        else if(n<10) { pc('-'); pc('1'); pc('\n'); continue; }

        ll slow=dec(n),fast=dec(slow),u=1,v=2;
        if(slow==1) { pc('1');  pc('\n'); continue; }

        if(fast==1) { pc('2');  pc('\n'); continue; }


        while(slow>9){

            slow = dec(slow);
            fast = dec(fast);
            if(fast<10){

                if(fast==1) print(v+1);
                break;
            }

            fast= dec(fast);
            
            if(fast<10){
                if(fast==1) print(v+2);
                break;
            }
            u++;
            v+=2;

            if(slow==fast){
                if(slow==1) print(u);  
                break;
            }

        
        }


        if(slow!=1 && fast!=1) { pc('-'); pc('1'); pc('\n');  }
       


    }



}