#include<bits/stdc++.h>
using namespace std;

#define prio
#define ll int
#define ma 100005
#define mp make_pair
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

using Vote = pair<int,int>;
using Unordered_map = unordered_map<Vote, bool, pair_hash>;


vector<int> grp[ma],revgrp[ma],rev[ma],final,temp; //used to store original grp , reverse graph , parentsccgraph , reversedparentsccgraph,finalresult,intermediate result
int scc[ma],v,total_scc=1,counte=0; //used to store scc id of every vertex, total connections of every scc,total sccs
bool visited[ma],fisited[ma]; //used for dfs and toposort
vector<vector<int>> scc_list; //used to store scc's
Unordered_map qscc; //used to check repetitions or visited check's for 
stack<int>st;	//used to store vertices 
queue<int>qu;	//used in checking total size 
bool dir;	//used in dfs




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
	else  {  scc[i]=total_scc; fisited[i]=true; z=revgrp[i].size(); }
 

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

inline void reach(int i)
{
	qu.push(i);
	
	while(!qu.empty()){
		
		int j=qu.front();
		qu.pop();
		if(!fisited[j])counte++;
		fisited[j]=true;
		for(int k=0;k<rev[j].size();k++){
			if(rev[j][k]!=j && rev[j][k]!=i  && !fisited[rev[j][k]]) qu.push(rev[j][k]);
		}


	}


}


int main(){
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);



	int e,i,j,k,l;
	bool flag;
	
	scan(v);
	scan(e);

	for(i=0;i<=v+2;i++) {
		visited[i]=fisited[i]=false;
		scc[i]=0;
	}

		
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
			total_scc++;
			scc_list.push_back(temp);
			vector<int> samp;
			temp.swap(samp);
			
		}


	}

	
	// step3 
	// for every edge , check if it belongs to 
	// different scc's 
	// if it is true , check if this start scc is 
	// already counted in end scc's list 
	// if not then increment conn[endscc] by 1
	// else ignore it 
	//not needed though
	//sort(scc+1,scc+v+1);
	//take the reverse graph of this 

	for(i=1;i<=v+2;i++) { fisited[i]=visited[i]=false; }
	for(i=1;i<=v;i++){
		for(j=0;j<grp[i].size();j++){
			if(scc[i] != scc[grp[i][j]]){
		
				if(qscc[mp(scc[i],scc[grp[i][j] ] ) ]  ==false){	
						qscc[ mp(scc[i],scc[grp[i][j]] ) ]=true;
						rev[scc[grp[i][j]]].push_back(scc[i]);
						//par[scc[i]].push_back(scc[grp[i][j]]);
						visited[scc[i]]=true;
				}

			}

		}

	}

	
	

	for(i=1;i<total_scc;i++){
		if(visited[i]==false && fisited[i]==false){
			//for(j=0;j<=total_scc;j++) fisited[j]=false;

			counte=0;
			reach(i);
			
			if(counte==(total_scc-1) ) {
				
				for(j=0;j<scc_list[i-1].size();j++){
					final.push_back(scc_list[i-1][j]);
				}


			}	

		}
	
	}

	if(final.size()==0){
		pc('0'); pc('\n');
		return 0;
	}

	sort(final.begin(),final.end());

	print(j);
	pc('\n');
	for(i=0;i<final.size();i++) {
		print(final[i]);
	}	

	pc('\n');
	//pc('\n');


}
