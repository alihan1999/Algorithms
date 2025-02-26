#include<bits/stdc++.h>
using namespace std;

long long inf =1e18;

int main(){

	int n,m;
	cin>>n>>m;
vector< long long> dist(n,inf);
vector< vector<int> > graph(n,vector<int>(n,1e9+5));
set<pair<int,int> > edges;
int x,y;
int w;
while(m--){
cin>>x>>y>>w;
x--,y--;
w=w*-1;
if(edges.find({x,y})==edges.end())edges.insert({x,y});
if(w<graph[x][y])graph[x][y]=w;

}
dist[0]=0;
bool cycle=false;
for(int k=0;k<n-1;++k){
for(auto e:edges){
int u=e.first;
int v=e.second;
if(dist[u]+graph[u][v]<dist[v])dist[v]=dist[u]+graph[u][v];
}

}

for(auto e:edges){
int u=e.first;
int v=e.second;
if(graph[u][v]+dist[u]<dist[v]){
cycle =true;
break;
}
}
if(cycle)cout<<-1;
else 
cout<<dist[n-1]*-1ll;



return 0;
}
