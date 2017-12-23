#include<bits/stdc++.h>
using namespace std;


#define ll int
#define gc getchar_unlocked



inline void scan(ll &x)
{
    register ll c = gc();
    x = 0;
    ll neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}


int a[1003],b[1003];

inline int floo(int a[], int b,int n){

	int l=0,h=n-1,mi,flo=-1;
	while(l<=h){
		mi =  l+(h-l)/2;

		if(a[mi]==b) return b;
		else if(a[mi]>b) h= mi-1;
		else {
			
			flo = a[mi];
			l = mi+1;
		}
		
	}

	return flo;
	
	
}


inline int cei(int a[], int b,int n){

	int l=0,h=n-1,mi,ce=-1;
	while(l<=h){
		mi =  l + (h-l)/2;

		if(a[mi]==b) return a[mi];
		else if(a[mi]<b) l = mi+1;
		else
		{
			ce = a[mi];
			h = mi-1;
		}

	}

	
	return ce;

	
}



int main()
{
	int t,n,m,i,j;
	scan(t);
	while(t--)
	{
		scan(m);
		for(i=0;i<m;i++) scan(a[i]);
		scan(n);
		for(i=0;i<n;i++) scan(b[i]);
		sort(a,a+m);


		j= 100000000;
		for(i=0;i<n;i++){
			
			int d = floo(a,b[i],m);
			int e = cei(a,b[i],m);

			if(d==-1 && e==-1) continue;
			else if(d==-1) j = min(j,e-b[i]);
			else if(e==-1) j = min(j,b[i]-d);
			else j = min( j , min(abs(b[i]-d) ,abs(e-b[i]) ) );				

			if(j==0) break;
		}

		printf("%d\n",j);
	
	}


}