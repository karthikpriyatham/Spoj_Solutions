#include<bits/stdc++.h>
using namespace std;


#define ma 102
//#define pri
#define eps 1e-6
#define gc getchar_unlocked

typedef struct nod
{
	int v;
	double d;
	bool operator <(const nod& other) const { return (d>other.d); }
}node;


inline void scan(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

double grp[102][102],dist[102];
int v;

priority_queue<node> pq;

void djkstra(void){

	
	pq.push((node){0,1.0});
	dist[0]=1.0;
	int i;


	for(i=0;i<v;i++)
	while (!pq.empty()){
        	node u = pq.top();
        	pq.pop();
        	
        	//if(u.v==v-1) break;

     	for (i=0;i<v;i++){

			if(i!=u.v && grp[u.v][i]>0.0){

            		double weight = grp[u.v][i];
            		if (dist[i] < (dist[u.v]*weight) ){
                		// Updating distance of v
               		dist[i] = dist[u.v] * weight;
               		pq.push((node){i,dist[i]});
               	}

               }

          }	 
    
     }

     double d = dist[v-1];
     d = d*100.0;
     printf("%0.6lf percent\n",d);
     while(!pq.empty()) pq.pop();


}

int main(){
	int m,i,j,k;
	double d;
	while(1){
		scan(v);
		if(v==0) break;
		scan(m);
		for(i=0;i<=v;i++) dist[i]=0.0;
		for(i=0;i<=v;i++) for(j=0;j<=v;j++) grp[i][j]=0.0;
		for(i=0;i<m;i++){
			scan(j); scan(k); scanf("%lf",&d);
			grp[j-1][k-1]=grp[k-1][j-1]=(d/100.0);
		}
		djkstra();
	}

}
