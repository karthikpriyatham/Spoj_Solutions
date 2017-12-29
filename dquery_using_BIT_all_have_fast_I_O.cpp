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


#define pc putchar_unlocked

char output_buffer[15];
inline void print(ll n) {
    if(n<0){
        n=-n;
        pc('-');
    }
    ll i=10;
    do{
        output_buffer[--i]=(n%10)+'0';
        n/=10;
    }while(n);
    do{
        pc(output_buffer[i]);
    }while(++i<10);
    pc('\n');

}

const int MAX = 300005;
const int MAX1 = 1e6 + 5;
int tree[MAX], p[MAX1], ans[MAX], a[MAX];
pair <int, pair<int, int> > pr[MAX];
 
void update(int idx, int val)
{
    while(idx < MAX)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
 
int read(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
int main()
{
    int n, q, x;
    scan(n);
    for(int i = 1;i <= n;++i)
        scan(a[i]);
    scan(q);
    for(int i = 0;i < q;++i)
    {
        scan(pr[i].second.first); scan(pr[i].first);
        pr[i].second.second = i;
    }
    sort(pr, pr + q);
    memset(p, -1, sizeof(p));
    memset(tree, 0, sizeof(tree));
    x = 0;
    for(int i = 1;i <= n;++i)
    {
        if(p[a[i]] != -1)
            update(p[a[i]], -1);
        p[a[i]] = i;
        update(i, 1);
        while(x < q and pr[x].first == i)
        {
            ans[pr[x].second.second] = read(pr[x].first) - read(pr[x].second.first-1);
            x++;
        }
    }
    for(int i = 0;i < q;++i)
        print(ans[i]);
    
    return 0;

}