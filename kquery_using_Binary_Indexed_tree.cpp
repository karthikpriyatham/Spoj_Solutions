#include<bits/stdc++.h>
using namespace std;

#define MAX1 300005
#define MAX 1000005
#define gc getchar_unlocked
#define pc putchar_unlocked

typedef struct nod{
    int v,l,r,i,t;  
}node;

inline bool cmp(node a,node b){
    if(a.v==b.v) return a.t > b.t;
    return a.v > b.v;
}

inline void scan(int &x){
    register char c = gc();
    x = 0;
    bool neg = false;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=true;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;

}


char output_buffer[15];
inline void print(int n) {
    if(n<0){
        n=-n;
        pc('-');
    }
    int i=10;
    do{
        output_buffer[--i]=(n%10)+'0';
        n/=10;
    }while(n);
    do{
        pc(output_buffer[i]);
    }while(++i<10);
    pc('\n');

}

int st[(MAX1<<2)],res[MAX+5];
node que[MAX+MAX1+5];

void update(int idx, int val)
{
    while(idx < MAX1)
    {
        st[idx] += val;
        idx += (idx & -idx);
    }
}
 
int query(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += st[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int i,j,k,l,n,q; 
    node a;
    
    for(i=0;i<MAX;i++){
        st[i]=0; 
    }


    scan(n);
    for(i=0;i<n;i++){
        scan(j);
        a.t=0; a.v=j; a.l=a.r=-1; a.i=i;
        que[i]=a;
    }

    scan(q);
    for(i=n;i<n+q;i++){
        scan(j); scan(k); scan(l);
        a.t=1; a.v=l; a.l=j; a.r=k; a.i=(i-n); 
        que[i]=a;
    }

    sort(que,que+n+q,cmp);
    
    for(i=0;i<n+q;i++){

        if(que[i].t==0){
            //if it is array type insert it into segment tree
            update(que[i].i+1,1);
        }
        else{

            res[que[i].i] = query(que[i].r)-( (l>0)?query(que[i].l-1):0);
        }

    }

    for(i=0;i<q;i++){
        print(res[i]);
    }

    return 0;

}