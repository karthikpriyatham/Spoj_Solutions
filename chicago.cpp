#include<bits/stdc++.h>
using namespace std;

#define ma 102
#define eps 1e-6
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

double dp[ma][ma];
int main(){
	int n,m,i,j,k,l;
	double d;
	while(1){

		scan(n);
		if(n==0) break;
		scan(m);

		for(i=0;i<=n;i++) for(j=0;j<=n;j++) dp[i][j]=0.0;
		for(i=0;i<=n;i++) dp[i][i]=1.0;
		for(i=0;i<m;i++){
			scan(j); scan(k); scanf("%lf",&d);
			dp[j-1][k-1]=dp[k-1][j-1]=(d/100.0);
		}

		for(k=0;k<n;k++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					dp[i][j]= max(dp[i][j],dp[i][k]*dp[k][j]);
				}
			}
		}

		d = (dp[0][n-1])*100.0;
		printf("%.6lf percent\n",d);


	}

}
