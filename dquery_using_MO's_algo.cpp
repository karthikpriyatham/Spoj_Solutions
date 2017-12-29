#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mp make_pair
int arr[30005],query[1000005],memo[200005];
class node
{
	public:vector< pair< int,pair<int,int> > >link;
};

#define vppi pair< int,pair<int,int> >
node dp[200];

#define gc getchar_unlocked

inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


#define pc putchar_unlocked

char output_buffer[15];
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
    pc('\n');

}


inline void add(int i,int *answer)
{
	query[arr[i]]++;
	if(query[arr[i]]==1) (*answer)++;
}

inline void remove(int i,int *answer)
{
    query[arr[i]]--;
   	if(query[arr[i]]==0) (*answer)--;

}

inline bool compare3( vppi a,vppi b)
{
	return a.second.second<b.second.second;
}

int main()
{
	int t,n,q,i,j,k,sq,a,b,m;
	scanint(n);
	for(i=0;i<n;i++) scanint(arr[i]);
	sq=ceil( (double)sqrt(n) );
	scanint(m);
	t=m;
	j=0;
	while(t--)
	{ 
	   
	   	scanint(a);
	   	scanint(b);
		i=(a-1)/sq;
	    dp[i].link.push_back(mp(j,mp(a-1,b-1)));
		j++;
			
	}
	
	for(i=0;i<sq;i++)
	{
		j=dp[i].link.size();
		if(j!=0) sort(dp[i].link.begin(),dp[i].link.end(),compare3);
	}
	
	memset(query,0,sizeof(query));
	
	int ans=0;
	
	
	int currentL=0,currentR=0,L,R;
	for(i=0;i<=sq;i++)
	{
		j=dp[i].link.size();
		for(k=0;k<j;k++)
	    {
	    	
	    	L=dp[i].link[k].second.first;
	    	R=dp[i].link[k].second.second;
	        while( currentL <L) 
		    {
		        remove(currentL,&ans);
                currentL++;
            }
    
	        while( currentL >L)
            {
                add(currentL-1,&ans);
                currentL--;
            }
            while( currentR <=R)
            {
               add(currentR,&ans);
               currentR++;
            }
            while( currentR >R+1)
            {
                remove(currentR-1,&ans);
                currentR--;	
		    }
		
		    memo[dp[i].link[k].first]=ans;
		    
	    }
	    
	}
	
	for(i=0;i<m;i++) 
	{
		print(memo[i]);
	}
}