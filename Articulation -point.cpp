#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define mx 10010

void articular_point(vector<int>graph[],int entry[],int low[],int parent[],int counter,bool visit[],bool ans[],int u)
{
    visit[u]=true;
    int cnt = 0 ;
    entry[u]=low[u]=++counter;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(visit[v]==false)
        {
            cnt++;
            parent[v]=u;
            articular_point(graph,entry,low,parent,counter,visit,ans,v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=entry[u]&&parent[u]!=-1) ans[u]=true;
            if(parent[u]==-1&&cnt>1) ans[u]=true;
        }
        else if(parent[u]!=v)
        {
            low[u]=min(low[u],entry[v]);
        }
    }
}
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(t--)
    {
        vector <int> graph[mx];
        int entry[mx],low[mx],parent[mx],counter=0;
        bool visit[mx],ans[mx];
        int N,M; // N is the number of points M is the number of connections
        scanf("%d%d",&N,&M);
        memset(visit,0,sizeof(visit));
        for(int i=1; i<=N; i++)graph[i].clear();
        for(int i=1; i<=N; i++) parent[i]=-1,ans[i]=0;
        while(M--)
        {
            int u,v ;  // There is a bidirectional connection between the point u and the point v
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=1; i<=N; i++) if(!visit[i]) articular_point(graph,entry,low,parent,counter,visit,ans,i);
        int cnt=0; // Number of Articular Points
        for(int i=1; i<=N; i++) if(ans[i]) cnt++;
        printf("Case %d: %d\n",c++,cnt);
        cnt=0;
        counter=0;
    }
    return 0;
}
