#include<bits/stdc++.h>
using namespace std;


// Binary Lifting Practice Code


vector< vector<int> > g;
vector<int> par;
vector<bool>vis;
vector< vector<int> > jump;
vector<int> d;

void dfs(int u){

	vis[u]=true;

	for(auto v:g[u]){
	
		if(!vis[v]){
		par[v]=u;
		d[v]=d[u]+1;
		dfs(v);
		}
	}
}


int LCA(int u,int v,int h){


	cout<<d[u]<<" "<<d[v]<<endl;
	if(d[u]-d[v]>0)swap(u,v);


	cout<<" u is now "<<u+1<<" and v is "<<v+1<<endl;

	int dif = d[v]-d[u];
	cout<<" dif is "<<dif<<endl;

	for(int k=h;k>=0;--k){
	if(dif & 1<<k)v = jump[v][k];
	cout<<"v updated to "<<v+1<<endl;
	}

	int cur_anc=0;

	for(int j = h ;j>=0;--j){
	
	if(jump[u][j]!=jump[v][j]){
	u=jump[u][j];
	v=jump[v][j];
	}
	else if(jump[u][j]!=-1)cur_anc=jump[u][j];
	}


return cur_anc;

}


int main(){

int n;
int r;

cin>>n>>r;

par.resize(n);
g.resize(n);
vis.resize(n);
d.resize(n);

int h =0;
int t = n;

while(t>1)h++,t/=2;

//cout<<h<<endl;

jump.resize(n,vector<int>(h+1,-1));

	int x,y;

	for(int i=0;i<n-1;++i){
	
		cin>>x>>y;
		x--,y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
r--;
d[r]=0;

	dfs(r);

	

	for(int i=0;i<n;++i){
	if(i==r)continue;
	jump[i][0]=par[i];
	}

	for(int k=1;k<=h;++k){
	
		for(int i=0;i<n;++i){
		
			if(jump[i][k-1]==-1 || jump[jump[i][k-1]][k-1]==-1)continue;
			else jump[i][k]=jump[jump[i][k-1]][k-1];
		}

	}

	
for(int i=0;i<n;++i){

	cout<<"the jumps of node "<<i+1<<" are as follows: "<<endl;

	for(int k=0;k<=h;++k){
	cout<<jump[i][k]+1<<" ";
	}
	cout<<endl;
}
cin>>x>>y;
x--,y--;
cout<<LCA(x,y,h)+1;


return 0;
}
