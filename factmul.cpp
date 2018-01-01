#include<bits/stdc++.h>
using namespace std;
const long long mod = 109546051211

int main(){
	long long n,p=1,q=1,i;
	scanf("%lld",&n);
	for(i=2;i<=n;i++){
		p=(p*i)%mod;
		q=(q%mod*p)%mod;
		if(q==0) break;
	}
	printf("%lld\n",q);
}