/**10^18 Fiboonacy Compute**/

#include "bits/stdc++.h"
using namespace std;

#define LL long long

map<LL,LL>Fib;
LL M;

LL Modular_exponen(LL x,LL y){
    LL res=1;
    while(y>0){
        if(y & 1){
            res*=x;
        }
        y=y>>1;
        x=x*x;
    }
    return res;
}

LL f(LL n,LL Depth,LL M){
    if(Fib.count(n))return Fib[n];
    LL k=n/2;
    if(n%2==0){
		return Fib[n] = (f(k, Depth+1,M)*f(k, Depth+1,M) + f(k-1, Depth+1,M)*f(k-1, Depth+1,M))%M;
    }
    else{
        return Fib[n] = (f(k, Depth+1,M)*f(k+1, Depth+1,M) + f(k-1, Depth+1,M)*f(k, Depth+1,M))%M;
    }
}


int main(){
    LL n,m;
    while(scanf("%lld %lld",&n,&m)==2){
        M=Modular_exponen(2,m);
        if(n==0)printf("0\n");
        else{
            Fib[0]=Fib[1]=1;
            printf("%lld\n",f(n-1,0,M));
        }
        Fib.clear();
    }
    return 0;
}

