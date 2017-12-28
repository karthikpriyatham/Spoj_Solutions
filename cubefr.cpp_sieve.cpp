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
bool spf[MAXN];
int dpf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[0] = false; dpf[0]=0;
    spf[1] = true;  dpf[1]=1;
    for (int i=2; i<MAXN; i++)
    {
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = true; dpf[i]=1;

    }
 
    // separately marking spf for every even
    // number as 2
    
    for (int i=2; (i*i*i)<MAXN; i++)
    {
    
        // if it is a cube free number,then do it for all its cube and its multiples 
        if (spf[i] == true)
        {

            int k=i*i*i;
            // marking SPF for all numbers divisible by i
            for (int j=k; j<MAXN; j+=k)
            {
 
                // marking spf[j] if it is not 
                // previously marked
                    spf[j] = false;
                    dpf[j]=0;
            }

        }

    
    }


    for(int i=1;i<MAXN;i++){
        dpf[i]=(dpf[i]+dpf[i-1]);
    }


}
 

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sieve();
    int t,n,i=1;
    scan(t);
    while(t--){
        pc('C'); pc('a'); pc('s'); pc('e'); pc(' '); print(i); pc(':'); pc(' ');
        scan(n);
    
        if(spf[n]==true) print(dpf[n]);
        else{
    
            pc('N'); pc('o'); pc('t'); pc(' '); pc('C'); pc('u'); pc('b'); pc('e');
            pc(' '); pc('F'); pc('r'); pc('e'); pc('e'); }

            pc('\n');
            i++;
        }


}


