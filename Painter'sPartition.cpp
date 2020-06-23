#include<iostream>
#include<climits>
using namespace std;

bool possible(int *a, int n, int k, int curr){
	int last=a[0];
    int cnt=1;
	int sum=0;
	for(int i=1;i<n;i++){
		if(last + a[i] > curr){
            cnt++;            
            last = a[i];
            if(cnt>k){
				return false;
			}
		}else{
            last += a[i];
        }
	}
	return true;
}


int main() {
	int p, n;
	cin>>p>>n;
	int a[1000];
	int sum=0;
	int mxm=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mxm=max(mxm,a[i]);
		sum+=a[i];
	}
	int s=mxm;
	int e=sum;
	int ans=INT_MAX;
	while(s<=e){
		int mid = (s+e)/2;
		if(possible(a,n,p,mid)){
			ans = mid;
			e=mid-1;
		}else{
			s=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
