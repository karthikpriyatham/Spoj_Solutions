#include<bits/stdc++.h>
using namespace std;

#define ll int
#define size 30005
#define gc getchar_unlocked
#define pc putchar_unlocked

inline int max(int a,int b) { return a>=b?a:b; }
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
	

}

typedef struct nod
{
	int uo,uc;
}node;

node segtree[3*size];
char arr[size];

inline void buildtree(int n,int l,int r)
{
	if(l>r) return ;
	else if(l==r)
	{
		if(arr[l]=='(') {segtree[n].uo=1; segtree[n].uc=0; }
		else {segtree[n].uo=0; segtree[n].uc=1; }
		return;
	}

	int mid = l+(r-l)/2,lx=2*n,rx=2*n +1;
	buildtree(lx,l,mid);
	buildtree(rx,mid+1,r);


	segtree[n].uo = segtree[rx].uo + max(0,segtree[lx].uo-segtree[rx].uc);
	segtree[n].uc = segtree[lx].uc + max(0,segtree[rx].uc-segtree[lx].uo);


}

inline void updatetree(int n,int ss,int se,int idx)
{
	if(ss>se || idx<ss || idx>se) return;

	if(ss==se && ss==idx)
	{
		//leaf node
		if(arr[ss]=='(') {segtree[n].uo=1; segtree[n].uc=0; }
		else {segtree[n].uo=0; segtree[n].uc=1; }
		return;
	}


	int mid = ss+(se-ss)/2,lx=2*n,rx=2*n +1;
	updatetree(lx,ss,mid,idx);
	updatetree(rx,mid+1,se,idx);


	segtree[n].uo = segtree[rx].uo + max(0,segtree[lx].uo-segtree[rx].uc);
	segtree[n].uc = segtree[lx].uc + max(0,segtree[rx].uc-segtree[lx].uo);



}


int main()
{
	int n,q,i;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for(int t =1;t<=10;t++)
	{
		pc('T'); pc('e'); pc('s'); pc('t');
		pc(' '); print(t); pc(':'); pc('\n');

		scan(n);
		for(i=0;i<n;i++) arr[i]=gc();
		//scanf("%s",arr);
		buildtree(1,0,n-1);
		scan(q);
		while(q--)
		{
			
			scan(i);
			if(i==0) {
				if(segtree[1].uo==0 && segtree[1].uc==0) { pc('Y'); pc('E'); pc('S'); pc('\n'); }
				else { pc('N'); pc('O'); pc('\n'); }
			}
			else
			{
				//index , segleft,segright, qul,qur
				arr[i-1]= (arr[i-1]==')')?'(':')'; 
				updatetree(1,0,n-1,i-1);
			}
			

		}

		

	
	}


}