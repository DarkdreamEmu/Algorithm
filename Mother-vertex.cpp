#include <bits/stdc++.h>
using namespace std;

vector<int>graph[100];
bool visited[100];
int n,m;

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

int mother_ver(){
    memset(visited,0,sizeof(visited));
    int v=0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            v=i;
        }
    }

    memset(visited,0,sizeof(visited));
    dfs(v);
    for(int i=0; i<n; i++){
        if(!visited){
            return -1;
        }
    }
    return v;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    int res=mother_ver();
    cout<<res<<endl;
    return 0;
}
