#include<bits/stdc++.h>
using namespace std;

vector<vector<char>>grid;
vector< vector<bool> > vis;
vector< vector< pair<int,int> > > par;

vector< pair<int,int>  > moves = {{0,1},{0,-1},{1,0},{-1,0}};


int r,c;

bool sane(int x,int y){
if(x<0 || x>=r || y<0 || y>=c)return false;
if(vis[x][y])return false;
return true;

}


bool bfs(int x,int y){

queue< pair<int,int> > q;
q.push({x,y});

vis[x][y]=true;
while(!q.empty()){

pair<int,int> t = q.front();
q.pop();

for(auto m:moves){
int a = m.first;
int b = m.second;

if(sane(t.first+a,t.second+b)){
par[t.first+a][t.second+b]={t.first,t.second};

vis[t.first+a][t.second+b]=true;

if(grid[t.first+a][t.second+b]=='B'){
return true;

};
q.push({t.first+a,t.second+b});

}
}


}
return false;

}




int main(){
cin>>r>>c;
grid.resize(r,vector<char>(c));
vis.resize(r,vector<bool>(c));
par.resize(r,vector<pair<int,int>>(c,{-1,-1}));
int ai,aj;
int bi,bj;
for(int i=0;i<r;++i){
for(int j=0;j<c;++j){
cin>>grid[i][j];
if(grid[i][j]=='A')ai=i,aj=j;
if(grid[i][j]=='#')vis[i][j]=true;
if(grid[i][j]=='B')bi=i,bj=j;
}

}


bool res = bfs(ai,aj);


if(!res)cout<<"NO"<<endl;
else{
cout<<"YES"<<endl;
string ans=""; 
while(par[bi][bj].first!=-1 && par[bi][bj].second!=-1){ 
	if(par[bi][bj].first - bi < 0)ans+="D";
       	if(par[bi][bj].first - bi > 0)ans+="U"; 
	if(par[bi][bj].second - bj > 0)ans+="L";
       	if(par[bi][bj].second - bj < 0) ans+="R";
	int tmp = bi;
       	bi = par[bi][bj].first; 
	bj = par[tmp][bj].second;  } 
reverse(ans.begin(),ans.end());
cout<<ans.size()<<endl;
cout<<ans;
}
return 0;

}
