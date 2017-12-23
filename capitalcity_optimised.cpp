#include<bits/stdc++.h>
using namespace std;

#define ll int
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);

#define MAXN 200000


inline void scan(int &x){
    register char c = gc();
    x = 0;
    bool neg = false;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=true;c=gc();}
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
    pc(' ');

}


vector< int > graph[ MAXN + 1 ], graphT[ MAXN + 1 ], sol;
bool visited[ MAXN + 1 ];
int comp[ MAXN + 1 ], in[ MAXN + 1 ];

void dfs1( int S ) {
    visited[ S ] = true;
    int i;
    for ( i = 0; i < graph[ S ].size(); ++i ) {
        if ( !visited[ graph[ S ][ i ] ] ) {
            dfs1( graph[ S ][ i ] );
        }
    }
    sol.push_back( S );
}

void dfs2( int S, int c ) {
    visited[ S ] = false;
    comp[ S ] = c;
    int i;
    for ( i = 0; i < graphT[ S ].size(); ++i ) {
        if ( visited[ graphT[ S ][ i ] ] ) {
            dfs2( graphT[ S ][ i ], c );
        }
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int t, i, N, v, j, compon, M, u, count, lim;
    //scanf( "%d%d", &N, &M );
    scan(N); scan(M);
    for ( i = 1; i <= N; ++i ) {
        visited[ i ] = false;
        graph[ i ].clear();
        graphT[ i ].clear();
        in[ i ] = 0;
    }
    for ( i = 1; i <= M; ++i ) {
        //scanf( "%d%d", &u, &v );
        scan(u); scan(v);
        graph[ v ].push_back( u );
        graphT[ u ].push_back( v );
    }
    for ( i = 1; i <= N; ++i ) {
        if ( !visited[ i ] ) {
            dfs1( i );
        }
    }
    compon = 0;
    for ( i = sol.size() - 1; i >= 0; --i ) {
        if ( visited[ sol[ i ] ] ) {
            dfs2( sol[ i ], compon++ );
        }
    }
    lim = compon;
    for ( i = 1; i <= N; ++i ) {
        for ( j = 0; j < graph[ i ].size(); ++j ) {
           if ( comp[ i ] != comp[ graph[ i ][ j ] ] ) {
                in[ comp[ graph[ i ][ j ] ] ] += 1;
            }
        }
    }
    count = 0;
    for ( i = 0; i < lim; ++i ) {
        if ( in[ i ] == 0 ) {
            ++count;
        }
    }
    if ( count > 1 ) {
        //printf( "0\n" ); 
        pc('0'); pc('\n');
    }
    else {
        count = 0;
        for ( i = 1; i <= N; ++i ) {
            if ( in[ comp[ i ] ] == 0 ) {
                ++count;
            }
        }
        print(count); pc('\n');
        for ( i = 1; i <= N; ++i ) {
            if ( in[ comp[ i ] ] == 0 ) {
                print(i);
            }
        }
        pc('\n');
    }
    return 0;
}