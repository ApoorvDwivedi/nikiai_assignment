#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

//function to multiply two matrices a*b
vector<vector<ll> > matmul(vector<vector<ll> > a,vector<vector<ll> > b)
{
	vector<vector<ll> > c(2,vector<ll> (2));
	int i,j,k;
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
	for(k=0;k<2;k++)
		c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
	return c;
	
}


// function to calculate power of a matrix mat^p
vector<vector<ll> > fastpow(vector<vector<ll> >mat, ll p)
{
	if(p==1)
		return mat;
	if(p%2)
		return matmul(mat,fastpow(mat,p-1));
	vector<vector<ll> > pmat = fastpow(mat,p/2);
	return matmul(pmat,pmat);
}


int main()
{
	int t,i;
	ll n;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		n=n+2; // ans is (n+2)th fibonacci number 
		
		vector<ll> f(2);
		
		f[0]=1;
		f[1]=1;

		vector<vector<ll> > mat(2,vector<ll> (2));
		
		mat[0][0] = 0;
		mat[0][1] = 1;
		mat[1][0] = 1;
		mat[1][1] = 1;

		if(n==1)
			return 1;
		
		mat=fastpow(mat,n-1);
	        
		ll ans=0;

		for(i=0;i<2;i++)
			ans=(ans+mat[0][i]*f[i])%mod;
		
		printf("%lld\n",ans);
		}
}
