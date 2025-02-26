#include<bits/stdc++.h>

using namespace std;

int r,c;

vector< vector<bool>> vis;
vector< pair<int,int>> moves = {{0,-1},{0,1},{1,0},{-1,0}};
vector< vector<char> > grid(r,vector<char>(c));


bool sanity_check(int x, int y){

	if(x<0 || x>=r || y<0 || y>=c){
	return false;
	}
	else if(vis[x][y]==true)return false;
	return true;

};

void dfs(int x,int y){
        vis[x][y]=true;
        for(auto m:moves){
        if(sanity_check(x+m.first,y+m.second))dfs(x+m.first,y+m.second);
        }
};



int dfs_vis(int x,int y){
	int count=0;
	for(int i=0;i<r;++i)
	{
	for(int j=0;j<c;++j){
	if(!vis[i][j])count++,dfs(i,j);
	}
	}

	return count;

};



int main(){
cin>>r>>c;

vis.resize(r,vector<bool>(c));
grid.resize(r,vector<char>(c));

for(int i=0;i<r;++i)
{
for(int j=0;j<c;++j){
	cin>>grid[i][j];
	if(grid[i][j]=='#')vis[i][j]=true;
}
}

int res = dfs_vis(0,0);

cout<<res;

return 0;
}
