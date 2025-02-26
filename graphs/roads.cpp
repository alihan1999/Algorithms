#include<bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector< vector<int> > graph;
vector<int> ans;
int ind=0;

void dfs_visit(int x)
{
        vis[x]=true;

        for(auto i:graph[x])if(!vis[i])dfs_visit(i);

}


void dfs(int n){
	for(int i=0;i<n;++i){
	if(!vis[i]){ans[ind++]=i;dfs_visit(i);}
	}

}

int main(){

int n,m;
cin>>n>>m;

vis.resize(n);
graph.resize(n);
ans.resize(n,-1);
int a,b;

while(m--){
cin>>a>>b;
a--;
b--;
graph[a].push_back(b);
graph[b].push_back(a);
}

dfs(n);


if(ind-1==0)cout<<0<<endl;
else{
cout<<ind-1<<endl;
for(int i=0;i<ind-1;++i){
cout<<ans[i]+1<<" "<<ans[i+1]+1<<endl;
}

}
return 0;

}
