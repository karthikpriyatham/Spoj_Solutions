#include<bits/stdc++.h>
using namespace std;
 
typedef struct Poin
{
    int x, y,i;
}Point;
 

typedef struct nod
{
  int x,y;
}node;

Point points[100005],ppp[100005];
stack<Point> S;
stack<int> X,Y;
 

#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);



inline void scan(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
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

// A globle point needed for  sorting points with reference
// to  the first point Used in compare function of qsort()
Point p0;
 
// A utility function to find next to top in a stack
Point nextToTop(void)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
// A utility function to swap two points
int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
// A utility function to return square of distance
// between p1 and p2
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
   // p(0,0)   , q(1,0)   r(2,0)
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    //print(val);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compa(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 

bool compare(Point p1, Point p2)
{

   int o = orientation(p0, p1, p2);
   if (o == 0)
     return (distSq(p0, p2) >= distSq(p0, p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
void convexHull(int n)
{
   // Find the bottommost point
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     // Pick the bottom-most or chose the left
     // most point in case of tie
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   // Place the bottom-most point at first position
   swap(points[0], points[min]);
 
   // Sort n-1 points with respect to the first point.
   // A point p1 comes before p2 in sorted ouput if p2
   // has larger polar angle (in counterclockwise
   // direction) than p1
   p0 = points[0];
   //printf("[[[%d,%d,%d]]] ",points[0].i,points[0].x,points[0].y);
   sort(points+1, points+n,compare);
   //printf("\n\nyoyo");

   for(int i=0;i<n;i++) ppp[i]=points[i];
   //pc('\n'); pc('\n');

   // If two or more points make same angle with p0,
   // Remove all but the one that is farthest from p0
   // Remember that, in above sorting, our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle.
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
 
      
       points[m] = points[i];
       m++;  // Update size of modified array
   }
 
   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if(m==1)
      {
        pc('0'); pc('.'); pc('0'); pc('0'); pc('\n'); print(points[0].i); pc('\n'); pc('\n');
        
      }
      else if(m==2)
      {

        double dist =0,mi=0;
        int midx=ppp[0].i;
        //printf("yoooohooo %d %d\n ",points[0].x,points[0].y);
        for(int i=1;i<n;i++)
        {
            dist = sqrt( (double) ( (ppp[0].x-ppp[i].x)*(ppp[0].x-ppp[i].x) )  +  (double) ( (ppp[0].y-ppp[i].y)* (ppp[0].y-ppp[i].y) )  );
            //printf("%d %lf  ",points[i].i,dist);

            if(dist>mi )
            {
              mi = dist;
              midx=ppp[i].i;
            }
        }

        
         printf("%.2lf\n",(2*mi));
         printf("%d %d\n",points[0].i,midx);
         printf("\n\n");



      }
 
    if(m<3) return;
   // Create an empty stack and push first three points
   // to it.
   
   S.push(points[0]); X.push(points[0].i);
   S.push(points[1]); X.push(points[1].i);
   S.push(points[2]); X.push(points[2].i);
 

   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (orientation(nextToTop(), S.top(), points[i]) != 2){   
          S.pop();
          X.pop();

      }
      S.push(points[i]);
      X.push(points[i].i);

   }
 
   // Now stack has the output points, print contents of stack
   double sum=0;
   Point fir = S.top();
   Point prev = S.top();
   S.pop();
   while (!S.empty())
   {
       Point p = S.top();
       sum += sqrt(  (double) ( (prev.x - p.x)*(prev.x-p.x) ) + (double) ( (prev.y - p.y)*(prev.y-p.y) ) ) ; 
       //cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
       prev = p;
       
   }

   sum += sqrt(  (double) ( (prev.x - fir.x)*(prev.x-fir.x) ) + (double) ( (prev.y - fir.y)*(prev.y-fir.y) ) ) ;   
   
   printf("%.2lf\n",sum);
   while(!X.empty())
   {
       Y.push(X.top());
       X.pop();
   }

   while(!Y.empty())
   {
      print(Y.top());
      Y.pop();
   }

   pc('\n');
   pc('\n');


}

int main()
{
  int t,n,i,j,k,l;
  scan(t);
  while(t--)
  {
      scan(n);
      unordered_map<string,bool> uop;

      l=0;
      for(i=0;i<n;i++) { 

        scan(j);
        scan(k);
        string s = to_string(j);
        s =s.append(to_string(k));
        if(uop[s]==false) 
        {
          uop[s]=true;
          points[l].x=j; points[l].y=k;
          points[l].i=i+1; 
          l++;
        }


      }

      n=l;

      if(n==1)
      {
        pc('0'); pc('.'); pc('0'); pc('0'); pc('\n'); pc('1'); pc('\n'); pc('\n');
        
      }
      else if(n==2)
      {
         double dist = sqrt( (double) ( (points[0].x-points[1].x)*(points[0].x-points[1].x) )  +  (double) ( (points[0].y-points[1].y)* (points[0].y-points[1].y) )  );
         printf("%.2lf\n",(2*dist));
        

         /* */
         int ymin = points[0].y, min = 0;
         for (int i = 1; i < n; i++)
         {
              int y = points[i].y;
 
              // Pick the bottom-most or chose the left
              // most point in case of tie
              if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
                  ymin = points[i].y, min = i;
          }
 
          // Place the bottom-most point at first position
          swap(points[0], points[min]);
 
          for(int i=0;i<n;i++)
          {
            print(points[i].i);
          }
          printf("\n\n");



      }
      else
        convexHull(n);      

  }




}