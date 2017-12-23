#include<stdio.h>
#define mod 1000000007

int main()
{
	int y,q,res,x;
	scan(q);
	
	while(q--){
		scan(y);
		res =1; 
 
      	x=3;
 
      	while (y > 0){
        		// If y is odd, multiply x with result
        		if (y %2==1){
          		res = (res*x);
          		if(res>mod) res = res%mod;
        		}
 
        		// n must be even now
        		y = y>>1; // y = y/2
        		x = (x*x);
        		if(x>mod) x = x%mod; // Change x to x^2
 
      	}
 
      	res = res*2;
      	if(res >mod) res = res%mod;
      	res = res-1;


	}


}