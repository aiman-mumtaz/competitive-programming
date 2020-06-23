#include <iostream>
#include<algorithm>
using namespace std;

int crossInversion(int *a, int s, int e){
    int ans = 0;
    int mid = (s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[100005];

    while(i<=mid && j<=e){
        if(a[i] <=a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
            ans += mid - (i-1);
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
	for(int i=s;i<=e;i++){
		a[i] =temp[i];
	}
    return ans;
}

int inversion(int *a, int s, int e){
    if(s>=e){
        return 0;
    }
    int mid = (s+e)/2;
    int l= inversion(a,s,mid);
    int r=inversion(a,mid+1,e);
    int x = crossInversion(a,s,e);

    return l+r+x;
}


int main() {
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int a[100005];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<inversion(a,0,n-1)<<"\n";
    }
    return 0;
}
