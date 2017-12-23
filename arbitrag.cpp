#include<bits/stdc++.h>
using namespace std;
#define ll long long


double dp[40][40],arr[40][40];

int main()
{
	char a[103],b[103];
	ll n,m,i,j,k,l=1;
	double d;
	while(1)
	{
		unordered_map<string,ll> uop;
		scanf("%lld",&n);
		if(n==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			uop[a]=i;
		}

		for(i=0;i<=n;i++) for(j=0;j<=n;j++) dp[i][j]=arr[i][j]=0;
		
		for(i=0;i<=n;i++) dp[i][i]=arr[i][i]=1.0;
		scanf("%lld",&m);
		for(i=0;i<m;i++)
		{
			scanf("%s %lf %s",a,&d,b);
			//printf("%lld %lld",uop[a],uop[b]);
			arr[uop[a]][uop[b]]=dp[uop[a]][uop[b]]=d;
		}


		//floyd warshall algorithm
		for (k = 0; k < n; k++)
    		{
        		// Pick all vertices as source one by one
        		for (i = 0; i < n; i++)
        		{
            		// Pick all vertices as destination for the
            		// above picked source
            		for (j = 0; j < n; j++)
            		{
               		// If vertex k is on the shortest path from
                		// i to j, then update the value of dist[i][j]
                		if (dp[i][k] * dp[k][j] > dp[i][j])
                    		dp[i][j] = dp[i][k] * dp[k][j];
            		
            		}
        

        		}
    

    		}

    		bool flag=false;
    		for(int i=0;i<n;i++)
    		{
    			if(dp[i][i]>1.0) { flag=true; break; }
    		}

    		if(flag) printf("Case %lld: Yes\n",l);
    		else printf("Case %lld: No\n",l);
    		l++;

	}



}