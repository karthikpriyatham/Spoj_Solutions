// Working program with FastReader
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;// Working program with FastReader
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
 
 
class TestClass {
 
  static class FastReader{
    BufferedReader br;
    StringTokenizer st;
 
    public FastReader(){
      br = new BufferedReader(new
      InputStreamReader(System.in));
    }
 
    String next(){
      while (st == null || !st.hasMoreElements()){
        try{
          st = new StringTokenizer(br.readLine());
        }
        catch (IOException e){
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }
 
 
 
    long nextLong(){
      return Long.parseLong(next());
    }
 
 
  }
 
  public static void main(String args[] ) throws Exception {
 
 
    // Write your code here
    FastReader s= new FastReader();
 
    long mod= 1000000007;
 
    long y,q,res,x=3;
  
    q=s.nextLong();
 
 
    while(q>0){

      q--;
 
      y = s.nextLong();
 
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
      System.out.println(res);
 
    }
 
 
 
  } 
 
 
}
