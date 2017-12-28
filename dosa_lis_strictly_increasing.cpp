#include<bits/stdc++.h>
using namespace std;


//http://codeforces.com/blog/entry/12274
//changing it to lower_bound gives lis


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



vector<int> d;

int main(){
    int n,j;
    scan(n);

    vector<int>::iterator it;

    for(int i=0;i<n;i++){

        scan(j);
        if(j-i>0){
            
            it = upper_bound(d.begin(), d.end(), (j-i));
            if (it == d.end()) d.push_back(j-i);
            else *it = (j-i);

        }


    }

    printf("%d\n",(n- (int)d.size()));


}