#include <bits/stdc++.h>
using namespace std;

int val[110];
int wt[110];
int dp[110][110];
int n;
int knapsack(int W,int n){
    int k[n+1][W+1];
    for(int i=0; i<=n; i++){
        for(int w=0; w<=W; w++){
            if(i==0||w==0){
                k[i][w]=0;
            }
            else if(wt[i-1]<=W){
                k[i][w] = max(val[i-1] + k[i-1][w-wt[i-1]],  k[i-1][w]);
            }
            else{
                k[i][w] = k[i-1][w];
            }
        }
    }
    return k[n][W];
}

int ans_me(int w,int ind){
    if(ind>=n)return 0;
    if(dp[ind][w]!=-1)return dp[ind][w];
    int A=0,B=0;
    if(w+cost[ind]<=total)A=value[ind]+ans_me(w+cost[ind],ind+1);
    B=ans_me(w,ind+1);
    return dp[ind][w]=max(A,B);
}

int main(){
    int w;
    cin>>w>>n;
    for(int i=1; i<=n; i++){
        cin>>wt[i]>>val[i];
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",knapsack(w,n));
    printf("%d\n",knapsack_recur(0,0));
    return 0;
}
