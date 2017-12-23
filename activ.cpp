#include<bits/stdc++.h>
using namespace std;


#define ll long long 
#define lol long long
#define mod 100000000
#define gc getchar_unlocked
#define pc putchar_unlocked

typedef struct nod
{
	ll st,en;
}node;

inline bool cmp(node a, node b) {
	return a.en< b.en;
}

inline int noofdigits(ll n)
{
	ll j=0;
	while(n>0)
	{
		n=n/10;
		j++;
	}
	return j;
}

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




inline ll floo(node a[], ll b,ll n){

	ll l=0,h=n-1,mi,flo=-1;
	while(l<=h){
		mi =  l+(h-l)/2;

		if(a[mi].en==b) return mi;
		else if(a[mi].en>b) h= mi-1;
		else {
			
			flo = mi;
			l = mi+1;
		}
		
	}

	return flo;
	
}

node arr[100005];
lol dp[100005][2]={0};

int main()
{

	ll t,n,i,j,k;
	while(1)
	{
		scan(n);
		if(n==-1) break;

		for(i=0;i<n;i++){ scan(arr[i].st); scan(arr[i].en); dp[i][0]=dp[i][1]=0; }
		sort(arr,arr+n,cmp);

		
		
		dp[0][1]=1;
		for(i=1;i<n;i++)
		{
			j = floo(arr,arr[i].st,n);
			dp[i][0] = dp[i-1][0] + dp[i-1][1];

			if(j!=-1) 
			{
				dp[i][1]=(1+dp[j][1]+dp[j][0])%mod;
			}
			else {
				dp[i][1]=1;
			}

		}

		ll j = (dp[n-1][0] + dp[n-1][1] )%mod;
		

		i= noofdigits(j);
		//printf("%lld\n",i);


		for(k=1;k<=(8-i);k++) pc('0');
		printf("%lld\n",j);
		

	}


}

