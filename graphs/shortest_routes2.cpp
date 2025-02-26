#include<bits/stdc++.h>
using namespace std;

const long long inf=1e18;

int main(){


	int n,m,q;
	cin>>n>>m>>q;

	vector< vector< long long> > g1(n, vector<long long>(n,inf) );
while(m--){
int x,y,w;
cin>>x>>y>>w;
x--,y--;
if(w<g1[x][y])g1[x][y]=w,g1[y][x]=w;

}
for(int i=0;i<n;++i)g1[i][i]=0;

for(int k=0;k<n;++k){

for(int i=0;i<n;++i){
for(int j=0;j<n;++j){

	if(g1[i][j]>g1[i][k]+g1[k][j])g1[i][j]=g1[i][k]+g1[k][j];
}
}
}

while(q--){
int x,y;
cin>>x>>y;
x--,y--;
if(g1[x][y]==inf)cout<<-1<<endl;
else cout<<g1[x][y]<<endl;
}

return 0;
}
