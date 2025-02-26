#include<bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<int> par;

vector< vector<int> > graph;
stack<int> ans;
int st=-1,nd=-1;
int n,m;

void dfs(int u){

	if(st!=-1&&nd!=-1)return;
	vis[u]=true;

	for(auto v:graph[u]){
	if(!vis[v]){
	par[v]=u;
		dfs(v);
	}
	else if(vis[v] && v!=par[u]){
	st=v;
	nd=u;
	return;
	}
	} 
}

void print_c(){
while(st!=nd)ans.push(st+1),st=par[st];
ans.push(st+1);
cout<<int(ans.size())+1<<endl;
int t=ans.top();
cout<<t<<" ";
ans.pop();
while(ans.size())cout<<ans.top()<<" ",ans.pop();
cout<<t;
}

void tour(){
for(int i=0;i<n;++i){
if(!vis[i] && st==-1 && nd==-1)dfs(i);
}
}

int main(){


cin>>n>>m;

graph.resize(n);
vis.resize(n);
par.resize(n);

int x,y;
while(m--){
cin>>x>>y;
x--,y--;
graph[x].push_back(y);
graph[y].push_back(x);

}

tour();

if(st==-1&&nd==-1)cout<<"IMPOSSIBLE";
else {
print_c();
}


return 0;
}
