#include<bits/stdc++.h>
using namespace std;

int mx =-1;

vector<int> p(1e6+5,0);

int manacher(string s){

int ind=-1;
int mid=0,r=0;

int n=s.size();

for(int i=1;i<n-1;++i){

	int reflex = 2*mid-i;

	if(i<r)p[i]=min(r-i,p[reflex]);
while(s[i+p[i]+1]==s[i-p[i]-1])p[i]++;
if(i+p[i]>r)r=i+p[i],mid=i;
if(p[i]>mx)ind=i,mx=p[i];

}
return ind;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin>>s;
	
	string pad = "$";

	for(auto c:s){
	pad+="#"+string(1,c);
	}
	pad+="#^";

	int ind = manacher(pad);
	int l = ind-p[ind];
	//cout<<ind<<endl;
	l=l/2;
		cout<<s.substr(l,mx);

}

