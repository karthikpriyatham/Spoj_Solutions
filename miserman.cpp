#include<bits/stdc++.h>
using namespace std;

int arr[102],arr2[102];

#define inf 10000000
#define gc getchar_unlocked

inline void scan(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main()
{
	int x,t,n,m,i,j,k,l,y,mi;
	
	    scan(n);
	    scan(m);
		for(i=0;i<n;i++)
		{
		   for(j=0;j<m;j++)
		   {
		   	    
		   	    scan(arr2[j]);
		   	    if(i!=0)
		   	    {
		   	    	
		   	    	k=(j-1>=0 ) ?arr[j-1]:inf;
					l=(j>=0)? arr[j]:inf;
					x=(j+1<m) ?arr[j+1]:inf;
					mi = min(x,min(k,l));
					if(mi!=inf) arr2[j]=arr2[j]+mi;
		   		
		   	    	
		   	    }
		   	    
				
		   }
		   
		   for(j=0;j<m;j++) arr[j]=arr2[j];
		   
		   
	    }	
	    
	  
	    x=arr[0];
	    for(j=1;j<m;j++){
	    		x=min(x,arr[j]);
		}
		
		printf("%d\n",x);
			
	
	
}