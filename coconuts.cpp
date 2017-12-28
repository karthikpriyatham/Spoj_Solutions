#include <stdio.h>
#include <queue>
#define DEBUG 0

using namespace std;

int nGuards, nPairs;

const int MAX = 302;
int graph[MAX][MAX];
int reg[MAX];
int SOURCE =0;
int SINK;

#define gc getchar_unlocked

inline void scan(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int mincut();
int augmentingPathExists();

int main(){

        FILE* file;
        if(DEBUG)file = fopen("d:\\input.txt", "r");
        while(1){
            if(DEBUG) fscanf(file, "%d %d", &nGuards, &nPairs);
            else { scan(nGuards); scan(nPairs); }

            if(nGuards==0 && nPairs==0)return 0;
            SINK = nGuards+1;


            for(int i=0;i<=nGuards;++i) for(int j=0;j<=nGuards+1;++j)graph[i][j] = -1;

            for(int i=0;i<=nGuards+1;++i)reg[i] = 0;
            for(int i=1;i<=nGuards;++i){
                if(DEBUG)fscanf(file, "%d", &reg[i]); else {scan(reg[i]);}
                if(reg[i]==1)graph[SOURCE][i] = 1;
                else graph[i][SINK] = 1;
            }

            for(int i=0;i<nPairs;++i){
                int a, b;
                if(DEBUG)fscanf(file,"%d %d", &a, &b);else {scan(a); scan(b);}
                graph[a][b] = 1;
                graph[b][a] = 1;
            }
            printf("%d\n", mincut());
 }
 return 0;
}

int path[MAX];

int augmentingPathExists(){
 queue<int> q;
 for(int i=0;i<nGuards+2;++i)path[i] = -1;
 for(int i=0;i<nGuards+2;++i)reg[i] = 0;

 bool stop = false;

 q.push(SOURCE);
 reg[SOURCE] = 1;
 int v;
 while(!q.empty()){
  v = q.front();
  q.pop();

  for(int i=1;i<=nGuards+1;++i){
   if(reg[i]!=1){
    if(graph[v][i]==1 || (i!=SINK && graph[i][v]==0)){
     reg[i] = 1;
     if(path[i]==-1)path[i] = v;
     if(i == SINK){
      stop = true;
      v = SINK;
      break;
                    }
     q.push(i);
    }
   }
  }
  if(stop)break;
 }
 return v;
}

int mincut(){
 int v = augmentingPathExists();
 int flow=0;
 while(v==SINK){
  for(int i=v;i!=SOURCE;i = path[i]){
   if(graph[path[i]][i]==1){
    graph[path[i]][i]=0;
   }
   else if(graph[i][path[i]]==0){
    graph[i][path[i]]=1;
   }
  }
  flow++;
  v = augmentingPathExists();
 }

 int cutCapacity=0;
 for(int i=SINK;i>=0;--i){
   if(reg[i]!=1)continue;
   for(int j=1;j<=nGuards+1;++j){
    if(reg[j]==0 && graph[i][j]==0){
                        cutCapacity++;
                }
   }
   if(i==0)break;
 }
 return cutCapacity;
}