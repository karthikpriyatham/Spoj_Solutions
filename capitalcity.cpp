#include<bits/stdc++.h>
using namespace std;

#define prioo
#define ll int
#define max 100005
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


vector<int> grp[max],revgrp[max],par[max],final;
bool visited[max],fisited[max];
Unordered_map pscc,qscc; 
int scc[max],conn[max];
vector<vector<int>> scc_list;
vector<int> temp;
stack<int>st;
queue<int>qu;
bool dir;
int v,total_scc=1;




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


void calc(int curr, int mai)
{
	qu.push(curr);
	while(!qu.empty())
	{
		int t= qu.front();
		qu.pop();
		if(mai!=t)
		{
			if(pscc[mp(mai,t)]==false)
			{
				pscc[mp(mai,t)]=true;
				conn[t]++;
				for(int j=0;j<par[t].size();j++){
					if( par[t][j]!=mai && pscc[mp(mai,par[t][j])]==false )
					{
						qu.push(par[t][j]);
					}

				}


			}


		}


	}




}


int main(){
	
	int e,i,j,k,l;
	bool flag;
	
		scan(v);
		scan(e);

		for(i=0;i<=v;i++) 
		{
			visited[i]=fisited[i]=false;
			scc[i]=conn[i]=0;
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

		#ifdef prio
			//print scc
			for(i=0;i<scc_list.size();i++)
			{
				for(j=0;j<scc_list[i].size();j++)
				{
					print(scc_list[i][j]);
				}
				pc('\n');
			}
		

		pc('\n'); pc('\n');
		printf("Total sccs are :%d\n",total_scc-1);
		for(i=1;i<=v;i++) print(scc[i]);
		pc('\n');pc('\n');
		#endif


		// step3 
		// for every edge , check if it belongs to 
		// different scc's 
		// if it is true , check if this start scc is 
		// already counted in end scc's list 
		// if not then increment conn[endscc] by 1
		// else ignore it 

		//not needed though
		//sort(scc+1,scc+v+1);

		for(i=1;i<=v;i++)
		{
			for(j=0;j<grp[i].size();j++)
			{
				if(scc[i] != scc[grp[i][j]])
				{
		
					if(qscc[mp(scc[i],scc[grp[i][j] ] ) ]  ==false)
					{	
						qscc[ mp(scc[i],scc[grp[i][j]] ) ]=true;
						par[scc[i]].push_back(scc[grp[i][j]]);
					}

				}

			}

		}

		for(i=1;i<=v;i++)
		{
			for(j=0;j<grp[i].size();j++)
			{
				if(scc[i] != scc[grp[i][j]])
				{
					if(pscc[ mp(scc[i],scc[grp[i][j]] )]==false)
					{

						//pscc[mp(scc[i],scc[grp[i][j]] ) ]=true;
						//conn[scc[grp[i][j]]]++;
						calc(scc[grp[i][j] ],scc[i]);
					
					}
				}
			}

		}

		//step4 -> for all scc's with total_scc-2 count 
		//in connected scc's , we will print all the elementsin 
		//scc_list[i-1]
		

		j=0;
		for(i=1;i<total_scc;i++) 
		{
			if(conn[i]==total_scc-2) 
			{
				j+=scc_list[i-1].size();
				for(k=0;k<scc_list[i-1].size();k++) final.push_back(scc_list[i-1][k]);
			}

		}

		sort(final.begin(),final.end());

		print(j);
		pc('\n');
		for(i=0;i<final.size();i++) {
			print(final[i]);
		}	

		pc('\n');
		pc('\n');

		



}
