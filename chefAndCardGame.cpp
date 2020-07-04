#include <bits/stdc++.h>
using namespace std;

int sumofD(int n){
    int cnt=0;
    while(n){
        int last=n%10;
        cnt+=last;
        n/=10;
    }
    return cnt;
}


int main() {
	int t;  cin>>t;
	while(t--){
	    int n;  cin>>n;
	    int scrm=0, scrc=0;
	    stack<int> c;
	    stack<int> m;
	    for(int i=0;i<n;i++){
	        int d1,d2;  cin>>d1>>d2;
	        c.push(d1);
	        m.push(d2);
          if(sumofD(c.top()) > sumofD(m.top())){
	            scrc=scrc+1;
	        } else if(sumofD(c.top()) < sumofD(m.top())){
	            scrm=scrm+1;
	        }else{
	           scrc=scrc+1;
	           scrm=scrm+1;
	        }
	        c.pop();
	        m.pop();
	    }
	    if(scrm < scrc){
	        cout<<0<<" "<<scrc<<"\n";
	    }
	    else if(scrm > scrc){
	        cout<<1<<" "<<scrm<<"\n";
	    }
	    else{
	        cout<<2<<" "<<scrc<<"\n";
	    }
	}
	return 0;
}
