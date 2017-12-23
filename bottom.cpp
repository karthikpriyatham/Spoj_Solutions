#include<bits/stdc++.h>
using namespace std;

#define prioo
#define ll int
#define max 5005
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);


vector<int> grp[max],revgrp[max];
bool visited[max],fisited[max];
vector<vector<int>> scc;
vector<int> temp;
stack<int>st;
bool dir;
int v;




inline void scan(ll &x){
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
	pc(' ');

}


inline void dfs(int i){

	int j,z;
	bool y;
	
	

	if(dir) { visited[i]=true; z= grp[i].size(); }
	else  { fisited[i]=true; z=revgrp[i].size(); }
 

	for(j=0;j<z;j++){

		if(dir) y = visited[grp[i][j]];
		else y = fisited[revgrp[i][j]];

		if( y==false ){

			if(dir) dfs(grp[i][j]);
		 	else dfs(revgrp[i][j]);
		 }
	
	}

	if(dir) st.push(i);
	else temp.push_back(i);
	

}

int main(){
	
	int e,i,j,k,l;
	bool flag;
	while(1){
		scan(v);

		if(v==0) break;
		
		for(i=0;i<=v;i++) {
			visited[i]=fisited[i]=false;
			vector<int> vp,vp2;
			grp[i].swap(vp); revgrp[i].swap(vp2);
		}

		scan(e);
		for(i=0;i<e;i++){
			scan(j); scan(k);
			grp[j].push_back(k);
			revgrp[k].push_back(j);
		}


		
		//step1 -> push all the vertices into the stack
		dir = true;
		for(i=1;i<=v;i++){
			if(visited[i]==false) dfs(i);
			
		}	


		//step2 -> pop all the entries of stack and for every entry 
		//add that entry to scc
		
		

		dir =false;
		while(!st.empty()){
			i = st.top();
			st.pop();

			if(!fisited[i]){
				dfs(i);
				scc.push_back(temp);
				vector<int> samp;
				temp.swap(samp);
			}


		}

		//step 3 -> for every scc element vector,
		//check if the element in its adjacency matrix is 
		//not present in the scc element ,if it is not present, 
		//discard the scc

		vector<int> bottoms;

		for(i=0;i<scc.size();i++){

			//first mark all the vertices in scc
			flag=true;
			unordered_map<int,bool> mpp;
			
			for(j=0;j<scc[i].size();j++) mpp[scc[i][j]]=true;
		

			for(j=0;j<scc[i].size();j++){
				k = scc[i][j];
				for(l=0;l<grp[k].size();l++){
					
					//discard this scc
					if(grp[k][l] && !mpp[grp[k][l]]){
						flag=false;
						break;
					}

				}

				if(flag==false){
					break;
				}


			}

			if(flag){
				for(j=0;j<scc[i].size();j++) bottoms.push_back(scc[i][j]);
			}	


		}



		sort(bottoms.begin(),bottoms.end());
		if(bottoms.size()==0) 
		{
				pc('\n');
		}
		else{
			for(i=0;i<bottoms.size()-1;i++) print(bottoms[i]);
			printf("%d\n",bottoms[bottoms.size()-1]);
		}

		vector< vector<int> > pp;
		scc.swap(pp);


	}


}
