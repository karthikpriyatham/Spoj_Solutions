#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);

void scan(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

char output_buffer[10];
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
    pc(' ');

}



int arr[1002],dp[1002][2];

int main(){
	
	int t,n,i,j,l;
	scan(t);
	while(t--){
		scan(n);
		for(i=0;i<n;i++){
			scan(arr[i]);
			dp[i][0]= dp[i][1]=0;
		}

		l=1;
		dp[0][0]=dp[0][1]=1;
		for(i=1;i<n;i++){
			for(j=i-1;j>=0;j--){
				if(arr[i]<arr[j]){
					//decreasing sum
					dp[i][0] = max(dp[i][0],dp[j][1]+1);
				}
				else{
					//increasingsequence
					dp[i][1]=max(dp[i][1],dp[j][0]+1);
				}
				

			}
			if(dp[i][0]==0) dp[i][0]=1;
			if(dp[i][1]==0) dp[i][1]=1;
	
			//pc('[')
			//print(dp[i][0]);
			//print(dp[i][1]);
			//pc(']');
			//pc('\n');
			l= max(l,max(dp[i][1],dp[i][0]) );

		}
		
		printf("%d\n",l);


	}


}