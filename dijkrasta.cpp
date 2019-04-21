#include "bits/stdc++.h"
using namespace std;

#define MX 100100
#define LL long long
vector< pair<LL,LL> >graph[MX];
bool visited[MX];
LL dist[MX];
int parent[MX];

class cmp {
    public:
    bool operator() ( pair<LL,LL> &A, pair<LL,LL> &B) {
        if(A.second>B.second)return true;
        else return false;
    }
};

LL dijkstra(int source,int des){
    for(int i=0; i<MX; i++){
        dist[i]=10000000000000;
        visited[i]=false;
    }
    priority_queue< pair<LL,LL>, vector< pair<LL,LL> >, cmp >PQ;
    dist[source]=0;
    parent[source]=-1;
    PQ.push(make_pair(source,0));
    visited[source]=true;
    while(!PQ.empty()){
        int u=PQ.top().first;
        PQ.pop();
        int sz=graph[u].size();
        if(u==des)return dist[des];
        for(int i=0; i<sz; i++){
            int v=graph[u][i].first;
            int w=graph[u][i].second;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                parent[v]=u;
                PQ.push(make_pair(v,dist[v]));
            }
        }
    }
    return -1;
}

void path(int s,int des){
    vector<int>pa;
    for(int v=des; v!=-1; v=parent[v]){
        pa.push_back(v);
    }
    reverse(pa.begin(),pa.end());
    for(int i=0; i<pa.size(); i++){
        printf("%d ",pa[i]);
    }
    printf("\n");
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u].push_back(make_pair(v,w));;
        graph[v].push_back(make_pair(u,w));
    }
    LL res=dijkstra(1,n);
    if(res==-1)puts("-1");
    else path(1,n);
    return 0;
}
