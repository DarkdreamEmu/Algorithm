#include <bits/stdc++.h>
using namespace std;

#define edge pair<int,int>
#define mx 1001

vector<pair<int, edge> >graph,mst;
int parent[mx],total,n,e;

int findset(int x, int *parent)
{
    if(x!=parent[x])
    {
        parent[x]=findset(parent[x],parent);
    }
    return parent[x];
}

void krushkal()
{
    int i,pu,pv;
    sort(graph.begin(), graph.end()); //increasing order//
    total=0;
    for(int i=0; i<e; i++)
    {
        pu=findset(graph[i].second.first,parent);
        pv=findset(graph[i].second.second,parent);
        if(pu!=pv)
        {
            mst.push_back(graph[i]);
            total+=graph[i].first;
            parent[pu]=parent[pv];
        }
    }
}
void reset()
{
    //reset appropriate variable from here
    //like graph.clear(),mst.clear();

    for(int i=1; i<=n; i++)parent[i]=i;
}

void print()
{
    int i,sz;
    sz=mst.size();
    for(int i=0; i<sz; i++)
    {
        printf("( %d", mst[i].second.first);
        printf(", %d )", mst[i].second.second);
        printf(": %d\n", mst[i].first);
    }
    printf("Minimum spanning tree = %d\n",total);
}

int main()
{
    int i,u,v,w;
    scanf("%d%d",&n,&e);
    reset();
    for(int i=0; i<e; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        graph.push_back(pair<int, edge>(w,edge(u,v)));
    }
    krushkal();
    print();
    return 0;
}
