/**Find the shortest path in unweighted graph.
   Search for connected components in the graph for O (n + m).**/

#include <bits/stdc++.h>
using namespace std;

#define mx 1000

vector<int>graph[mx];
bool visited[mx];
int dis[mx];
int p[mx];

int bfs(int s,int d){
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s]=1;
    dis[s]=0;
    p[s]=-1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == d){
            return true;
        }
        int sz=graph[u].size();
        for(int i=0; i<sz; i++){
            int v=graph[u][i];
            if(!visited[v]){
                visited[v]=1;
                p[v]=u;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return false;
}

void print_path(int d){
    vector<int>path;
    for(int v=d; v!=-1; v=p[v]){
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    printf("Path :");
    for(int i=0; i<path.size(); i++){
        printf("%d ",path[i]);
    }
    printf("\n");
    return ;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s,d;
    scanf("%d%d",&s,&d);
    int res=bfs(s,d);
    if(!res){
        printf("NO PATH\n");
    }
    else{
        print_path(d);
    }
    return 0;
}
