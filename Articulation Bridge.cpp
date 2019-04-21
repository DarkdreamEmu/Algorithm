#include "bits/stdc++.h"
using namespace std;


#define MX 1001

vector<int>g[MX];
int Articulation_Bridge[MX][MX],Already[MX][MX];
int Visited[MX],Discover[MX],Low[MX],parent[MX],tme=0;
set< pair<int,int> >ans;

void clear(){
    tme=0;
    ans.clear();
	for(int i=0; i<MX; i++){
		Visited[i]=Discover[i]=Low[i]=0;
		parent[i]=-1;
		g[i].clear();
	}
	memset(Articulation_Bridge,0,sizeof(Articulation_Bridge));
    memset(Already,0,sizeof(Already));
}

void AB(int u){
	Visited[u]=1;
	Discover[u]=Low[u]=++tme;
	int child=0;
	for(int i=0; i<g[u].size(); i++){
		int v=g[u][i];
		 if(!Visited[v]){
			child++;
			parent[v]=u;
			AB(v);
			Low[u]=min(Low[u],Low[v]);
		    if(Discover[u]<Low[v]){
				ans.insert( make_pair(min(u,v),max(u,v)));
			}
		}
		else if(v!=parent[u]){
		    Low[u]=min(Low[u],Low[v]);
		}
	}
}


int main(){
	int n,m;
	int cs=1;
	while(scanf("%d %d",&n,&m) && (n+m)){
		clear();
		for(int i=0; i<m; i++){
			int u,v;
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		printf("%d\n\n",cs++);
		AB(1);
		for(auto x : ans){
			cout<<x.first<<" "<<x.second<<endl;
		}
		printf("#\n");
	}
	return 0;
}
