#include<bits/stdc++.h>
using namespace std;


int n;
int m;

long long inf = 1e18;

vector<vector<long long>> capacity;
vector<vector<int>> adj;
vector<int> par;

vector<deque<int>> ans;

long long bfs(int s,int t, vector<int>& par){

	queue<pair<int,long long>> q;

	fill(par.begin(),par.end(),-1);
	par[s]=-2;

	q.push({s,inf});

	while(!q.empty()){
	
		long long flow = q.front().second;
		int u = q.front().first;
		q.pop();

		for(int v=0;v<n;++v){
		
			if(adj[u][v] && par[v]==-1 && capacity[u][v]){
			par[v]=u;
			long long new_flow = min(capacity[u][v],flow);
			
			if(v==t)return new_flow;
			q.push({v,new_flow});
			}
		
		}
	}

	return 0;
}




set<int> min_cut(int s){


	//returns the cut with the target node

	queue<int> q;
	q.push(s);
	set<int> vertex;
	for(int i=0;i<n;++i)if(i!=s)vertex.insert(i);

	while(!q.empty()){
	
		int u = q.front();
		q.pop();
		
		for(int v=0;v<n;++v){
			if(adj[u][v] && vertex.count(v)&&capacity[u][v])q.push(v),vertex.erase(v),par[v]=u;

		}
	}
	
	return vertex;
}




long long max_flow(int s,int t){


	vector<int> par(n);

	long long mx=0;

	long long flow;
	
	while(flow=bfs(s,t,par)){
	
		mx+=flow;

	
		deque<int> path;
		
		int cur = t;
		int prev;

		while(cur!=s){
		
			path.push_front(cur);
			prev = par[cur];

			capacity[prev][cur]-=flow;
			capacity[cur][prev]+=flow;
			cur=prev;
		}
		path.push_front(s);
	
	ans.push_back(path);
	}

//	cout<<"max flow is "<<mx<<endl;
return mx;

}




int main(){

	cin>>n>>m;

	adj.resize(n,vector<int> (n));
	capacity.resize(n,vector<long long>(n));
	par.resize(n);

	int x,y;

	for(int i=0;i<m;++i){
	
	cin>>x>>y;
	x--,y--;
	
	adj[x][y]=1;
	adj[y][x]=1;

	capacity[x][y]+=1;

	}


	long long res = max_flow(0,n-1);
	cout<<res<<endl;

	set<int> cut1 = min_cut(0);
	set<int> cut2 = min_cut(n-1);

	for(auto x:cut1){
	
		for(auto y:cut2){
	
		if(capacity[x][y]==0)cout<<x+1<<" "<<y+1<<endl;	
	}
	}
	return 0;
}
