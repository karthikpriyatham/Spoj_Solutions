#include<bits/stdc++.h>
using namespace std;

//https://stackoverflow.com/questions/11499157/number-of-pairs-that-share-at-least-one-digit

#define ll long
#define gc getchar_unlocked
#define pc putchar_unlocked

int arr[1025],barr[1025][2];

inline void scan(ll &x){

    register char c = gc();
    x = 0;
    bool neg = false;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=true;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;

}

int main(){

	ll n,i,j,k,l,m=0;
	scan(n);
	for(i=0;i<1025;i++) arr[i]=0;
	
	
	for(i=0;i<n;i++){

		scan(j);
		
		l=0;
		while(j>0){
			k=j%10;
			l|=(1<<k);
			j=j/10;
		}
		
		arr[l]++;

	}

	m=0;
	for(i=0;i<1025;i++){
		if(arr[i]>0){
			barr[m][0]=arr[i];
			barr[m][1]=i;
			m++;
		}
	}



	ll sum=0;
	for(i=0;i<m;i++){

		ll dum=0;
		dum+= ( (barr[i][0]*(barr[i][0]-1)) )/2;
		for(j=i+1;j<m;j++){

			if(barr[i][1]&barr[j][1]) dum+= (barr[i][0]*barr[j][0]);
		}
		sum+=dum;
	
	}

	printf("%ld\n",sum);
	return 0;

}