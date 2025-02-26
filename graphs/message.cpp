#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > graph;
vector<int> par;
vector<bool> vis;
stack<int> ans;
void bfs(int s)
{
queue<int> q;
q.push(s);
vis[s]=true;

while(!q.empty()){
int t = q.front();
q.pop();

for(auto n:graph[t])
{
if(!vis[n])par[n]=t,q.push(n),vis[n]=true;
}

}

}

void path(int s){
	ans.push(s+1);
	if(par[s]==-1)return;
	path(par[s]);


}

int main(){

int n,m;
cin>>n>>m;

graph.resize(n);
par.resize(n,-1);
vis.resize(n);

int a,b;

while(m--){
cin>>a>>b;
a--,b--;
graph[a].push_back(b);
graph[b].push_back(a);
}
bfs(0);

if(par[n-1]==-1)cout<<"IMPOSSIBLE";
else{
path(n-1);
cout<<ans.size()<<endl;
while(!ans.empty()){
cout<<ans.top()<<" ";
ans.pop();
}
}
return 0;

}
