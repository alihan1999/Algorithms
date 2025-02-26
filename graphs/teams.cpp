#include<bits/stdc++.h>
using namespace std;

vector< vector<int> >  graph;
vector<int> label;
vector<bool> vis;
int n,m;

bool bfs(int s)
{
queue<int> q;
q.push(s);
vis[s]=true;

while(!q.empty()){
	int t = q.front();
	q.pop();
	
	for(auto n:graph[t]){
	if(!vis[n]){
		vis[n]=true;
	label[n]=1-label[t];
	q.push(n);
	}
	if(label[n]==label[t])return false;
	}


}



return true;
};

bool traverse(int n){
bool r = true;
for(int i=0;i<n;++i){
if(!vis[i])r&=bfs(i);
}
return r;
}

int main(){
cin>>n>>m;
graph.resize(n);
label.resize(n,0);
vis.resize(n,false);
int a,b;

while(m--){
cin>>a>>b;
a--;
b--;
graph[a].push_back(b);
graph[b].push_back(a);

}

bool res = traverse(n);

if(!res)cout<<"IMPOSSIBLE";
else{
for(int i=0;i<n;++i){
cout<<label[i]+1<<" ";
}
}




return 0;
}
