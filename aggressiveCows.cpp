#include<iostream>
#include<algorithm>
using namespace std;

bool canPlace(int *stalls, int n, int c, int minSep){
	int lastCow = stalls[0];
	int count=1;
	for(int i=1;i<n;i++){
		if(stalls[i]-lastCow >= minSep){
			lastCow = stalls[i];
			count++;
			if(count == c){
				return true;
			}
		}
	}
	return false;
}
int main() {
	int n,c;	cin>>n>>c;
	int stalls[100005];
	for(int i=0;i<n;i++){
		cin>>stalls[i];
	}
	sort(stalls,stalls+n);
	int s = 0;
	int e=stalls[n-1]-stalls[0];
	int ans = 0;
	while(s<=e){
		int mid = (s+e)>>1;
		if(canPlace(stalls,n,c,mid)){
			ans = mid;
			s=mid+1;
		}else{
			e=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
