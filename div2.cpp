#include<bits/stdc++.h>
using namespace std;

#define pc putchar_unlocked
#define gc getchar_unlocked



char output_buffer[15];
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
    pc('\n');

}


int div2[1000001];
bool p[1000001];


int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    div2[0] = div2[1] = p[0] = p[1] =0;

    for(int i=2;i<1000001;i++) div2[i]=1;
    for(int i=2;i<1000001;i++) p[i]=1;
    for(long long i=2;i<1000001;i++){
        if(p[i]==0) continue;

        div2[i]=0;
        for(long long j=i*2;j<1000001;j+=i){
            p[j]=0;
        }
        long long k;
       
        for(long long j=1,k=i*i;k<1000001;j++,k=i*i*j){
            div2[k]=0;
        }
    }
    
    int c=0;
    for(int i=2;i<1000001;i++){
        if(div2[i]==1){
            c++;
            if(c%108==0) print(i);
        }
    }
    return 0;

}