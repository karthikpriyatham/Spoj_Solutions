#include <cstdio>
#include <vector>
#include <algorithm>
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



//typedef pair< int, int > pii;
//typedef pair< int, pii > edge;
const int MAX = 10001;


typedef struct edg{
	int u,v,w;
}edge;

typedef struct subse{
    int parent;
    int rank;
}subset;


edge edges[100000];
subset subsets[MAX];

inline bool cmp(edge a, edge b){
	return a.w < b.w;
}

inline int find(int i){
    // find root and make root as parent of i (path compression)
	
	while(subsets[i].parent!=i)
	{
		i = subsets[i].parent;
	}
	return subsets[i].parent;
    /*if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
    return subsets[i].parent; */
}


inline void Union(int x, int y){
    int xroot = find(x);
    int yroot = find(y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }

}




int main() {
	int t, i, n, e, u, v, w, cost, sz,k=0;
	char dump[20];
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scan(t);
	while(t--) {
		//edges.clear();
		scan(n);
		for(i=0;i<=n;i++) { subsets[i].parent=i; subsets[i].rank =0; }
		k=0;
		for(i = 1; i <= n; i++) {
			
			scanf("%s",dump);
			scan(e);
			while(e--) {

				//scanf("%d%d", &v, &w);
				scan(v);
				scan(w);
				//if(v > i) edges.push_back(edge(w, pii(i, v)));
				if(v > i) {
					edges[k].u = i;
					edges[k].v = v;
					edges[k].w = w;
					k++;
				}


			}


		}
		sort(edges,edges+k,cmp);
		
		for(cost=i=0; i < k; i++) {
			u = find(edges[i].u);
			v = find(edges[i].v);
			w = edges[i].w;
			if(u != v) {
				cost += w;
				Union(u,v);
				//parent[u] = parent[v];
			}

		}
		printf("%d\n", cost);
	}
	return 0;
}