#include<bits/stdc++.h>
using namespace std;
#define max 200
#define inf 4*max 
// you may update it to 2*(m+n) based on m,n values 
int mx,nx;
int dp[max][max];
char arr[max][max];

#define pc(x) putchar_unlocked(x);
 
inline void print(int n) {
	if(n<0){
		n=-n;
		pc('-');
	}
	int i=10;
	char output_buffer[10];
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		pc(output_buffer[i]);
	}while(++i<10);
	pc(' ');

}


int main()
{
	int t,i,j,x,y,z,u;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&mx,&nx);
		for(i=0;i<mx;i++)
		{
			scanf("%s",arr[i]);
			for(j=0;j<nx;j++)
			{
				if(arr[i][j]=='1') dp[i][j]=0;
				else dp[i][j]=inf;

			}

		}


		//forward check top down

		bool flag=false;
		for(i=0;i<mx;i++)
		{
			for(j=0;j<nx;j++)
			{
				if(arr[i][j]=='0')
				{
					x = (i-1>=0 && dp[i-1][j]!=inf)? (dp[i-1][j]+1):inf;
					y = (j-1>=0 && dp[i][j-1]!=inf)? (dp[i][j-1]+1):inf;
					z = (i-1>=0 && j-1>=0 && dp[i-1][j-1]!=inf)? (dp[i-1][j-1]+2):inf;

					u = min(x,min(y,z));

					if(u!=inf) dp[i][j]=min(dp[i][j],u);

				}


			}

		}

		//backward check bottom up	
		for(i=mx-1;i>=0;i--)
		{
			for(j=nx-1;j>=0;j--)
			{
				if(arr[i][j]=='0')
				{
					x = (i+1<mx && dp[i+1][j]!=inf)? (dp[i+1][j]+1):inf;
					y = (j+1<nx && dp[i][j+1]!=inf)? (dp[i][j+1]+1):inf;
					z = ( (i+1<mx && j+1<nx) && dp[i+1][j+1]!=inf)? (dp[i+1][j+1]+2):inf;

					u = min(x,min(y,z));

					if(u!=inf) dp[i][j]=min(dp[i][j],u);


				}


			}

		}

		for(i=0;i<mx;i++)
		{
			for(j=0;j<nx;j++)
			{
				print(dp[i][j]);
			}
			pc('\n');

		}

		pc('\n');




	}



}
