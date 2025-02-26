#include<bits/stdc++.h>
using namespace std;

long long inf =1e18;



int main(){

int n,m;
cin>>n>>m;


vector<long long> dist(n,inf);
vector<vector< pair<long long,long long> > > graph(n);
priority_queue<pair<long long ,long long>,vector< pair<long long, long long> > ,greater<pair<long long,long long> > > pq;

int x,y,w;
while(m--){
cin>>x>>y>>w;
x--,y--;

graph[x].push_back({w,y});
grapg[y].push_back({w,x});


}
dist[0]=0;
pq.push({0,0});

while(!pq.empty()){
int u = pq.top().second;
long long d = pq.top().first;
pq.pop();
if(d>dist[u])continue;
for(auto x:graph[u]){

	if(dist[u]+x.first<dist[x.second]){
	dist[x.second]=dist[u]+x.first;
	pq.push({dist[x.second],x.second});
	}
}
}
for(int i=0;i<n;++i){

	if(dist[i]==inf)cout<<-1<<endl;
	cout<<dist[i]<<endl;

}
}
