#include<iostream>
using namespace std;
#define ll long long
bool isPossible(ll n, ll m, ll x, ll y, ll curr){
	if((curr*x)<=(m+(y*(n-curr)))){
		return true;
	}
	return false;
}


int main() {
	ll n,m,x,y;	cin>>n>>m>>x>>y;
	ll s=0;
	ll e=n;
	ll ans=0;
	while(s<=e){
		ll mid=(s+e)/2;
		if(isPossible(n,m,x,y,mid)){
			ans=mid;
			s=mid+1;
		}else{
			e=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
