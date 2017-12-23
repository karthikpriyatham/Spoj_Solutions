#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MX 3000

ll md1=100003LL;
ll md2=101111111111LL;
ll bs1=257LL,bs2=100019LL;
ll Hs[MX+2][MX+2];
ll Hs2[MX+2][MX+2];

char txt[MX+2][MX+2];
char pat[MX+2][MX+2];
ll x,y; /// Rolling Range;

inline void RollingHash2D(char s[][MX+2],int r,int c){
    ///Rolling Hash for matrix -s of size r*c.
    ///Hs[i][j] gives the hash val of length 'y' starting from row-i,col-j;

    ///At First, Row wise Y-len Hash calculation
    ll pw=1LL;/// pw for power of base
    for(ll i=0;i<r;i++){
        ll h=0LL; /// h for hash value
        for(ll j=0;j<y;j++){
            h=( h*bs1+(s[ i ][ j ]-'a'+1) )%md1;
            if(i==0)pw=(pw*bs1)%md1;
        }
        Hs[i][0]=h;
        for(ll j=1;j<(c-y+1);j++){
            h=( h*bs1+ ( s[ i ][ j+y-1 ] -'a'+1) )%md1; ///Adding last char;
            h=( h-( (s[ i ][ j-1 ]-'a'+1)*pw)%md1+md1 )%md1; ///Subtracting starting char of current window;
            Hs[i][j]=h;
        }
    }

    ///Column Wise Hash calculation;
    pw=1LL;
    for(ll j=0;j<(c-y+1);j++){
        ll h=0LL;
        for(ll i=0;i<x;i++){
            h=( h*bs2+ Hs[i][j] )%md2;
            if(j==0)pw=(pw*bs2)%md2;
        }
        Hs2[0][j]=h;
        for(ll i=1;i<(r-x+1);i++){
            h=( h*bs2+ Hs[ i+x-1 ][ j ] )%md2; ///Adding last Hash-1 val;
            h=( h-( Hs[ i-1 ][ j ]*pw )%md2+md2 )%md2; ///Removing beg Hash Val;
            Hs2[ i ][ j ]=h;
        }
    }
}


int main()
{

	ll n1,n2,m1,m2,i,j,k;
	scanf("%lld %lld",&n1,&n2);
	for(i=0;i<n1;i++)
	{
		scanf("%s",txt[i]);
	}

	scanf("%lld %lld",&m1,&m2);
	for(i=0;i<m1;i++)
	{
		scanf("%s",pat[i]);
	}

    x=n1; y = n2;

    if(m1<n1 || m2<n2) { /// Special case for small main matrix than pattern
            printf("NO MATCH FOUND...\n");
            return 1;
    }
     
    RollingHash2D(txt,n1,n2);
    
    ll vl=Hs2[0][0];
    
    RollingHash2D(pat,m1,m2);

    bool flag =false;
    for(i=0;i<m1-n1+1;i++){
        
        for(j=0;j<m2-n2+1;j++)
        {
                if( Hs2[i][j]==vl ) 
                {
                    printf("(%lld,%lld)\n",(i+1),(j+1));
                    flag =true;
                }

        }

        
    }

    if(flag==false)
    {
        printf("NO MATCH FOUND...\n");
    }



}