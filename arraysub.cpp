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

deque<ll> dq;
ll arr[100005];
vector<ll> vpp;

int main()
{
	ll t,n,i,j,k;

	scan(n);
	for(i=0;i<n;i++)
	{
		scan(arr[i]);
		//first pop those elements less than i;
		//from front
	}

	scan(k);	

	for(i=0;i<n;i++)
	{
		
		if(i>=k)
		{
			vpp.push_back(arr[dq.front()]);

			while(dq.size()>0 && dq.front()<=(i-k) )
			{
				dq.pop_front();
			}	
		
		}

		while(dq.size()>0 && arr[i]>=arr[dq.back()])
		{
			dq.pop_back();
		}

		dq.push_back(i);

	
	}

	vpp.push_back(arr[dq.front()]);

	while(dq.size()>0)
	{
		dq.pop_front();
	}	

	for(i=0;i<vpp.size();i++) printf("%d ",vpp[i]); 
	printf("\n");


}