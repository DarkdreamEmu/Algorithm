#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <functional>

using namespace std;
const int mx=1e4+5;
typedef pair<long long,int>PII;
bool marked[mx];
vector<PII>adj[mx];

long long prim(int x)
{
    priority_queue< PII,vector<PII>,greater<PII> >Q;
    int y;
    long long mincost=0;
    PII p;
    Q.push(make_pair(0,x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p=Q.top();
        Q.pop();
        x=p.second;
        //checking for circle
        if(marked[x]==true)
        {
            continue;
        }
        mincost+=p.first;
        marked[x]=true;
        for(int i=0; i<adj[x].size(); i++)
        {
            y=adj[x][i].second;
            if(marked[y]==false)
            {
                Q.push(adj[x][i]);
            }
        }
    }
    return mincost;
}

int main()
{
    long long int nodes,edges,x,y;
    long long int mincost,weight;
    while(cin>>nodes>>edges&&nodes!=0&&edges!=0)//&&nodes!=0&&weight!=0)
    {
        int sum=0;
        //adj.erase( adj.begin(), adj.end() );
        memset(marked,false,sizeof(marked));
        for(int i=0; i<=nodes; i++)adj[i].clear();
        //memset()
        for(int i=0; i<edges; i++)
        {
            cin>>x>>y>>weight;
            //sum+=weight;
            adj[x].push_back(make_pair(weight, y));
            adj[y].push_back(make_pair(weight, x));
        }
        // Selecting 1 as the starting node
        mincost=prim(1);
        cout<<mincost<<endl;
    }
    return 0;
}
