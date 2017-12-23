/*
	Author : Karthik
*/

#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked
#define mod 1000003


inline void scan(int &x){
    register char c = gc();
    x = 0;
    bool neg = false;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=true;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline int gcd(int u,int v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    if(u<v) { int temp=u; u=v; v=temp; }
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}


int arr[55][55][55];
int dp[55][55][55][55];

int main()
{

	for(int j=1;j<=50;j++){
		for(int k=1;k<=50;k++){
			int l=1;
			for(int i=1;i<=50;i++){
				int u =i+j;
				int v =j+k;
				if(gcd(u,v)==1){
					arr[j][k][l]= i;
					l++;
				}

			}
			arr[j][k][0]=l;

		}

	}

	
	for(int i=0;i<=50;i++) {
		for(int j=0;j<=50;j++){
			for(int k=0;k<=50;k++){
				for(int l=0;l<=50;l++){
					dp[i][j][k][l]=0;
				}
			}
		}

	}

	

	for(int j=1;j<=50;j++){

		for(int i=1;i<=j;i++){

			for(int k=1;k<=j;k++){
				dp[2][j][i][k]=1;

			}

		}

	}


	for(int i=3;i<=50;i++){

		for(int r=1;r<=50;r++){
			
			for(int j=1;j<=r;j++){

				for(int k=1;k<=r;k++){

					//choose colrs from arr[j][k] and 
					for(int m=1;m<arr[j][k][0];m++){

						if(arr[j][k][m]<=r ){
							
	dp[i][r][j][k]= (dp[i][r][j][k] + dp[i-1][r][arr[j][k][m]][j] )%mod;

						}

					}


				}


			}

			


		}
	

	
	}


	int t,n,m,u=1;
	scan(t);
	while(t--){
		
		printf("Case %d: ",u);
		u++;
		
		scan(n);
		scan(m);
		
		if(n==1) { printf("%d\n",m); continue; }

		if(m==0) { pc('0'); pc('\n');  continue;  }

		int sum=0;
		for(int j=1;j<=m;j++){

			for(int k=1;k<=m;k++){

				sum = (sum+dp[n][m][j][k])%mod;
			
			}
		
		}
		printf("%d\n",sum);

	}




} 
