#include<bits/stdc++.h>
using namespace std;


#define ll  int
#define fl double
#define mod 1000000007
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);

char output_buffer[15];

inline void scan(ll &x){
    register char c = gc();
    x = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    
}

typedef struct poi
{
	double x,y;
	int i;
}point;


typedef struct tup{
	point a,b;
	double mi;

}tupl;

bool cmpx(point a,point b){
	return (a.x<b.x);
}

bool cmpy(point a,point b){
	return a.y<b.y;
}


// A utility function to find the distance between two points
fl dist(point p1, point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
 
// A Brute Force method to return the smallest distance between two points
// in P[] of size n
tupl bruteForce(point P[], int n)
{
    fl mi = FLT_MAX;
    point x,y;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < mi)
            {
            	x=P[i];
            	y=P[j];
                mi = dist(P[i], P[j]);
            } 
    
    tupl t; t.a=x; t.b=y; t.mi =mi;
    return t;

}
 
// A utility function to find minimum of two fl values
fl min(fl x, fl y)
{
    return (x < y)? x : y;
}
 
 
// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
tupl stripClosest(point strip[], int size, fl d)
{
    fl mi = d;  // Initialize the minimum distance as d
 
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    point x,y;
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < mi; ++j)
            if (dist(strip[i],strip[j]) < mi)
            {
                mi = dist(strip[i], strip[j]);
                x=strip[i]; y=strip[j];
 		  }

    tupl t; t.a=x; t.b=y; t.mi =mi;
    return t;
}
 
// A recursive function to find the smallest distance. The array Px contains
// all points sorted according to x coordinates and Py contains all points
// sorted according to y coordinates
tupl closestUtil(point Px[], point Py[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);
 
    // Find the middle point
    int mid = n/2;
    point midPoint = Px[mid];
 
 
    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    point Pyl[mid+1];   // y sorted points on left of vertical line
    point Pyr[n-mid-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++)
    {
      if (Py[i].x <= midPoint.x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }
 
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    tupl dl = closestUtil(Px, Pyl, mid);
    tupl dr = closestUtil(Px + mid, Pyr, n-mid);
 
    // Find the smaller of two distances
    fl d = min(dl.mi, dr.mi);
    tupl mo ;
    if(dl.mi==d) mo =dl;
    else mo =dr; 
   
    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;
 
    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    tupl tem = stripClosest(strip,j,d);
    if(tem.mi>d) return  mo;
    return tem;
    

}
 


int main()
{
	int n,i,j,k;
	scan(n);
	point px[n+1],py[n+1];
	for(i=0;i<n;i++){
		scan(j); scan(k);
		px[i].x = (fl)j; px[i].y= (fl)k;
		py[i].x = (fl)j; py[i].y= (fl)k;
		px[i].i=py[i].i=i;
	}
	sort(px,px+n,cmpx);
	sort(py,py+n,cmpy);
	tupl x =closestUtil(px,py,n);

	int a = (x.a.i < x.b.i)?x.a.i: x.b.i;
	int b = (x.a.i < x.b.i)?x.b.i: x.a.i;
	printf("%d %d %.6lf\n",a,b,x.mi);

}