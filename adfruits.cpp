#include<bits/stdc++.h>
using namespace std;

#define pc putchar_unlocked
int L[1002][1002];
char X[102],Y[102],lcs[102];

void lcso(int m, int n )
{
   
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   // Following code is used to print LCS
   int index = L[m][n];
 
   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character
 
   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   map<int,int> mpp;
   //map<int,bool> upp;

   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {

      	mpp[i-1]=(j-1);


          lcs[index-1] = X[i-1]; // Put current character in result

          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
   // Print the lcs
   //cout << "LCS of " << X << " and " << Y << " is " << lcs;

   map<int,int>::iterator it;
   int prev=0,prev2=0;
   for(it = mpp.begin();it!=mpp.end();it++)
   {
  
   	  for(int i=prev;i<it->first;i++) pc(X[i]);
   	  for(int i=prev2;i<it->second;i++) pc(Y[i]);
  	  pc(X[it->first]);
  	  prev = it->first+1;
  	  prev2=it->second+1;

   }

   for(int i= prev;i<m;i++) pc(X[i]);
   for(int i= prev2;i<n;i++) pc(Y[i]);

    pc('\n');
}


int main()
{

	while(scanf("%s",X)!=EOF)
	{
		scanf("%s",Y);
		int m = strlen(X);
		int n = strlen(Y);
		lcso(m,n);

	}	





}

