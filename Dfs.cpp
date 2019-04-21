#include <bits/stdc++.h>
using namespace std;
#define mx 1000

vector<int>graph[mx];
bool visited[mx];
int dis[mx];
int p[mx];

void dfs(int s){
    visited[s]=1;
    int sz=graph[s].size();
    for(int i=0; i<sz; i++){
        int v=graph[s][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    return 0;
}
