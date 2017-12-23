#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);

int color[2002],n;
bool interaction[2002][2002];



inline void scan(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

bool flag=true;

void dfs(int i,int par)
{

	if(flag==false) return;

	if(par==-1) color[i]=1; //red
	else{
		color[i]=(color[par]==1)?2:1;
	}

	for(int j=1;j<=n;j++)
	{
		if(j==i || interaction[i][j]==false) continue;
		
		if(color[j]==0) dfs(j,i);
		else if( color[j]!=0 && color[j]==color[i]) {
			flag=false;
			return ;
		}

	}


}

int main()
{
	int t,m,i,j=1,l=1;
	scan(t);
	while(t--)
	{
		flag=true;
		printf("Scenario #%d:\n",l);
		scan(n);
		scan(m);
		for(i=0;i<=n;i++) 
		{
			color[i]=0;
			for(j=0;j<=n;j++) interaction[i][j]=false;
		}
		while(m--){
			scan(i);
			scan(j);
			interaction[i][j]=interaction[j][i]=true;
		}

		for(i=1;i<=n;i++){
			if(color[i]==0) dfs(i,-1);
			if(flag==false ) break;
		}

		if(flag) printf("No suspicious bugs found!\n");
		else printf("Suspicious bugs found!\n");
		l++;


	}


	return 0;
}