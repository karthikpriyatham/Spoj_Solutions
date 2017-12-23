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



int main()
{
	ll n,i,j=1,u,v,w,a,b,c,cura,curb,curc;
	while(1)
	{
		scan(n);
		if(n==0) break;

		for(i=0;i<n;i++) 
		{

			scan(u); scan(v); scan(w);
			//scanf("%d %d %d",&u,&v,&w);
			if(i==0){
				cura = 0;
				curb = v;
				curc = w +v;
			}
			else{

				if(i==1){
					cura = u + b;
					curb = v + min( cura,min(b,c));
 				}
 				else{
					cura = u + min(a,b); 
					curb = v + min( min(a,b),min(c,cura) );
				}
				curc = w + min(min(b,c),curb);

			}

			a = cura; b =curb; c= curc;
			//printf("%lld. %lld %lld %lld\n",i,a,b,c);
		
		}

		printf("%d. %d\n",j,curb);
		j++;

	} 

}