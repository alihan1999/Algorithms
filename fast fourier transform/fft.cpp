#include<bits/stdc++.h>
using namespace std;
using cd = complex<double>;

const double PI = acos(-1);
const int mod=1009;
int k;

void fft(vector<cd>& a,bool invert){

  int n = a.size();
    if (n == 1)
        return;

    double angle = 2*PI/n*(invert?-1:1);

    cd w(1),wn(cos(angle),sin(angle));

    vector<cd> ev(n/2),odd(n/2);
    for(int i=0;2*i<n;++i){
    odd[i]=a[2*i+1];
    ev[i]=a[2*i];
    }

    fft(ev,invert);
    fft(odd,invert);

    for(int i=0;2*i<n;++i){
    
	    a[i] = ev[i] + w*odd[i];
	    a[i+n/2]=ev[i] - w*odd[i];
	    if(invert)a[i]/=2,a[i+n/2]/=2;
	    w = w*wn;
    }
}

void multiply(vector<cd> & a, vector<cd> & b) {

	int n=1;
	while(n<a.size()+b.size())n<<=1;

	a.resize(n);
	b.resize(n);

	fft(a,false);
	fft(b,false);

	for(int i=0;i<n;++i)a[i]*=b[i];

	fft(a,true);

	
	for(int i=0;i<n;++i){
	long long v = ((long long)round(a[i].real())) % mod ;
		a[i].real(i>k?0:v);
	a[i].imag(0);
	}
	
	

	while(n>1 && a[n-1].real()==0)n--,a.pop_back();

}



int main(){

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

	int n,m;
	cin>>n>>m>>k;

	vector<int> arr(n);
	vector<int> co(m+1);
	vector<vector<cd> > poly;

	

	for(int i=0;i<n;++i){
	
		scanf("%d",&arr[i]);
		co[arr[i]]++;
	}

	for(int i=0;i<co.size();++i){
	if(co[i])poly.push_back(vector<cd>(co[i]+1,cd(1,0)));
	}
	
	int r=poly.size()-1;
	int it = (poly.size()+1)>>1;
	while(it--){
	
		for(int i=0;i<(r+1)/2;++i){
		
			int mir = r-i;
		        multiply(poly[i],poly[mir]);
		}
		r/=2;
	
	}
	cout<<(long long)(round(real(poly[0][k])))%mod<<endl;
	


	

return 0;
}




