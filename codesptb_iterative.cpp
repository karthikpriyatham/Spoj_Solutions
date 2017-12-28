#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked

inline void scan(int &x)
{
    register int c = gc();
    x = 0;
    bool neg = false;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=true;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}


char output_buffer[15];
inline void print(long int n) {
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
  

}

int a[200001],BIT[1000005];

// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
int getSum(int BITree[], int index)
{
    int sum = 0; // Initialize result
 
    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BITree) at given index
// in BITree.  The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;
 
       // Update index to that of parent in update View
       index += index & (-index);
    }
}
 
// Returns inversion count arr[0..n-1]
int getInvCount(int arr[], int n)
{
    long int invcount = 0; // Initialize result
 
    // Find maximum element in arr[]
    int maxElement = 0;
    for (int i=0; i<n; i++)
        if (maxElement < arr[i])
            maxElement = arr[i];
 
    // Create a BIT with size equal to maxElement+1 (Extra
    // one is used so that elements can be directly be
    // used as index)
    for (int i=1; i<=maxElement; i++)
        BIT[i] = 0;
 
    // Traverse all elements from right.
    for (int i=n-1; i>=0; i--)
    {
        // Get count of elements smaller than arr[i]
        invcount += getSum(BIT, arr[i]-1);
 
        // Add current element to BIT
        updateBIT(BIT, maxElement, arr[i], 1);
    }
 
    return invcount;
}


int main()
{
  int n,t,i;
  scan(t);
  while(t--)
  {
    scan(n);
    for(i=0;i<n;i++) scan(a[i]);
    
    print(getInvCount(a,n));
    pc('\n');
  }

}