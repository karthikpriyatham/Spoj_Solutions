#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORI(i,b,a) for(int i=b;i>=a;--i)
#define MOD 1988

int dp[5005][5005];

int main()
{
	int t;
	int n, k;

	FOR(k,0,5001)
	{
		dp[k][1] = 1;
		dp[0][k] = 1;
	}
	FOR(containers,2,5001)
	{
		FOR(balls,1,5001)
		{

			dp[balls][containers] = (((balls-containers)>=0?dp[balls-containers][containers]:0) + dp[balls][containers-1])%MOD;
		}
	}

	while(true)
	{
		cin>>n>>k;
		if(!n && !k) break;
		cout<<dp[n-k][k]<<endl;
	}
}