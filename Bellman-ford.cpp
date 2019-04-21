#include "bits/stdc++.h"
using namespace std;

#define MAX 100001

int n,m;
int dist[MAX];

struct node{
	int u,v,w;
}graph[MAX];

void BellmanFord(int source){
	for(int i=0; i<MAX; i++){
		dist[i]=INT_MAX;
	}
	dist[source]=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int u = graph[j].u;
			int v = graph[j].v;
			int w = graph[j].w;
			if(dist[v]>dist[u]+w && dist[u]!=INT_MAX){
				dist[v]=dist[u]+w;
			}
		}
	}
	for(int j=0; j<m; j++){
		int u = graph[j].u;
		int v = graph[j].v;
		int w = graph[j].w;
		if(dist[v]>dist[u]+w){
			puts("Here is a Negative cylce");
			return ;
		}
	}
	for(int i=0; i<n; i++){
		cout<<"Distance From Source is : "<<dist[i]<<endl;
	}
	return ;
}

int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[i]={u,v,w};
	}
	int source;
	cin>>source;
	BellmanFord(source);
	return 0;
}

