#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked
#define INF 1000000


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


typedef struct nod
{
	int v,w;
	
}node;

bool operator <(node a,node other)  { return (a.w<other.w); }

int dist[10005];
priority_queue<node> pq;

inline void djkstra(vector<node>graph[],int a,int b){

	cin.tie(NULL);
     ios_base::sync_with_stdio(false);

	int i;
	pq.push((node){a,0});
	dist[a]=0;
	

	while (!pq.empty()){
        	node u = pq.top();
        	pq.pop();
        	//print(u.v);
        	
        	//if(u.v==b) break;

     	for (i=0;i<graph[u.v].size();i++){

			if(i!=u.v && dist[graph[u.v][i].v]> dist[u.v]+graph[u.v][i].w ){

                	// Updating distance of v
               	dist[graph[u.v][i].v] = dist[u.v] + graph[u.v][i].w;
               	pq.push((node){graph[u.v][i].v,dist[graph[u.v][i].v]});

               }

          }	 
    
     }

     if(dist[b]==INF) { pc('N'); pc('O'); pc('\n'); }
     else print(dist[b]);
    	
    	while(!pq.empty()) pq.pop();

   

}



int main(){

	int t,v,k,i,j,l,m,a,b;
	scan(t);

	while(t--){

		scan(v); scan(k);
		for(i=0;i<=v;i++) { dist[i]=INF; } 
		vector<node>graph[v+1];
		for(i=0;i<k;i++){
			scan(j); scan(l); scan(m);
			graph[j].push_back( (node){l,m} );
		}
		scan(a); scan(b);
		djkstra(graph,a,b);
		
	}

}
