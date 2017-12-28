#include<bits/stdc++.h>
using namespace std;

#define pc putchar_unlocked
#define gc getchar_unlocked
#define siz 2000005
#define ll int

bool isprime[siz];
int segtree[4*siz],arr[siz];

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


inline void sieve(void){
	for(int i=0;i<siz;i++) isprime[i]=true;

	isprime[0]=isprime[1]=false;
	isprime[2]=true;

	for(int i=4;i<siz;i+=2) isprime[i]=false;

	for(int i=3;i<siz;i+=2){
		if(isprime[i]==true){
			for(int j=2*i;j<siz;j+=i) isprime[j]=false;
		}
	}

	
}

inline void buildtree(int n,int l,int r)
{
	if(l>r) return ;
	else if(l==r)
	{
		segtree[n]=(isprime[arr[l]]==true)?1:0;
		return;
	}

	int mid = l+(r-l)/2,lx=2*n,rx=2*n +1;
	buildtree(lx,l,mid);
	buildtree(rx,mid+1,r);


	segtree[n] = segtree[rx] + segtree[lx];

}

inline void updatetree(int n,int ss,int se,int qs,int qe,int up)
{
	if(ss>se || qe<ss || qs>se) return;

	if(qs<=ss && se<=qe)
	{
		//leaf node
		segtree[n] = (se-ss+1)*up;
		return;
	}


	int mid = ss+(se-ss)/2,lx=2*n,rx=2*n+1;
	updatetree(lx,ss,mid,qs,qe,up);
	updatetree(rx,mid+1,se,qs,qe,up);

	segtree[n] = segtree[rx] + segtree[lx];


}


inline int query(int node, int start, int end, int l, int r)
{
    if(r < start || end < l || start>end)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start && end <= r)
    {
        // range represented by a node is completely inside the given range
        return segtree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = start + (end-start) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);

}


int main(){
	int t,n,q,x,y,v,i,j=1,k=1;
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	sieve();
	scan(t);
	while(t--){
		
		pc('C'); pc('a'); pc('s'); pc('e'); pc(' '); print(k); pc(':'); pc('\n');
		scan(n);
		scan(q);
		for(i=0;i<n;i++) scan(arr[i]);
		buildtree(1,0,n-1);
		
		while(q--){

			scan(i); scan(x); scan(y);
			if(i==0){
				scan(v);
				v = (isprime[v]==true) ?1:0;
				updatetree(1,0,n-1,x-1,y-1,v);
				print(segtree[1]);
				pc('\n');
			}
			else {

				j= query(1,0,n-1,x-1,y-1);
				print(j);
				pc('\n');
			}


		
		}

		k++;

	}


}
