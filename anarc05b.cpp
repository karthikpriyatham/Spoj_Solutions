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

ll a[10005],b[10005];
int main()
{
	ll n,m,i,j,k,c,d;
	
	while(1)
	{

		scan(n);
		if(n==0) break;
		for(i=0;i<n;i++) scan(a[i]);
		scan(m);
		for(i=0;i<m;i++) scan(b[i]);

		i=0,j=0,k=0,c=0,d=0;		
		while(i<n && j<m)
		{
			if(a[i]==b[j])
			{
				k = k+a[i]+max(c,d);
				i++; j++; c=0; d=0;
			}
			else if(a[i]<b[j])
			{
				c = c+a[i];
				i++;
			}
			else
			{
				d = d+b[j];
				j++;
			}


		}

		while(i<n)
		{
			c+=a[i];
			i++;
		}

		while(j<m)
		{
			d+=b[j];
			j++;
		}

		k= k+max(c,d);

		printf("%d\n",k);


	}


}