#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define MX 101010

vector<int>G[MX];
int V[MX],E[MX],parent[MX],N,Level[MX],F[MX],tme=1,L[MX];

struct Node{
    int level,value;
};

Node Tree[MX*3];

void dfs(int node,int par,int lev){
    V[node]=1;
    Level[node]=lev;
    if(F[node]==0){
        F[node]=tme;
    }
    L[tme]=Level[node];
    E[tme++]=node;
    for(auto x: G[node]){
        if(!V[x]){
            dfs(x,node,lev+1);
            L[tme]=Level[node];
            E[tme++]=node;
        }
    }
}

Node combine(Node a,Node b){
    if(a.level<b.level)return a;
    else return b;
}

void Build(int node,int beg,int en){
    if(beg==en){
        Tree[node].level=L[beg];
        Tree[node].value=E[beg];
        return ;
    }
    int mid=(beg+en)/2;
    int Left=node*2;
    int Right=Left+1;
    Build(Left,beg,mid);
    Build(Right,mid+1,en);
    Tree[node]=combine(Tree[Left],Tree[Right]);
}

Node query(int node,int beg,int en,int L,int R){
    if(beg>=L&&en<=R){
        return Tree[node];
    }
    if(beg>R||en<L){
        Node tmp;
        tmp.level=INT_MAX;
        tmp.value=-1;
        return tmp;
    }
    int mid=(beg+en)/2;
    int Left=node*2;
    int Right=Left+1;
    Node A=query(Left,beg,mid,L,R);
    Node B=query(Right,mid+1,en,L,R);
    return combine(A,B);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>N;
    for(int i=0; i<N-1; i++){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    memset(V,0,sizeof(V));
    dfs(1,-1,0);
    tme;
    Build(1,1,tme);
    int m;
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        int L=F[u];
        int R=F[v];
        if(L>R)swap(L,R);
        Node res=query(1,1,tme,L,R);
        cout<<res.value<<" "<<res.level<<endl;
    }
    return 0;
}
