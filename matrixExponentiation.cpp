/*
f(n) = c1*f(n-1) + c2*f(n-2) + ... ck*f(n-k)
step 1: Find k(no of values f(n) depends upon)
step 2: Find first k terms and store it in a vector F1
step 3: Find Transformation Matrix T of size k x k such that T * F(i) = F(i+1)
	 	|0	1	0	0	0	0|				 
		|0	0	1	0	0	0|					 
		|0	0	0	1	0	0|	
	T=	|0	0	0	0	1	0|
		|0	0	0	0	0	1|
		|.  	.	.	.	.	.|         		 
		|ck 	.	.	. 	c2     c1|		     
	we know that F(n) = T^(n-1)*F(1), so to compute F(n) find power of T
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000000

ll k;
vector<ll> a,b,c;

vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B) {
	vector<vector<ll> > C(k+1,vector<ll>(k+1));
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			for(int x=1;x<=k;x++){
				C[i][j] = (C[i][j] + (A[i][x] * B[x][j])%MOD)%MOD;
			}
		}
	}
	return C;
}


vector<vector<ll> > power(vector<vector<ll> > A, ll p){
	if(p==1){
		return A;
	}
    //Recursive
	if(p&1){
		return multiply(A,power(A,p-1));
	} else {
		vector<vector<ll> > X = power(A,p/2);
		return multiply(X,X);
	}
}

ll compute(ll n) {
	//base 
	if(n==0){
		return 0;
	}
	if(n<=k){
		return b[n-1];
	}
	//F1 vector
	vector<ll> F1(k+1);
	for(int i = 1; i<= k; i++){
		F1[i]= b[i-1];
	}
	
	//Transformation matrix T
	vector<vector<ll> > T(k+1,vector<ll>(k+1));
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j+1){
            if(i<k){
                if(j == i+1){
                    T[i][j]=1;
                } else {
                    T[i][j] = 0;
                }
                continue;
            }
			//last row -> coefficients in reverse order
			T[i][j] = c[k-j];
		}
	}
	
	//find T^n-1
	T = power(T,n-1);
	
	//Multiply F1[i] and T[1[i]
	ll ans =0;
	for(int i=1;i<=k;i++){
		ans = (ans + (T[1][i]*F1[i])%MOD)%MOD;
	}
	return ans;
}


int main() {
	ll t,n,num;
	cin>>t;
	while(t--) {
		cin>>k;
		
		//F1 vector initialisation
		for(int i=0;i<k;i++){
			cin>>num;
			b.push_back(num);
		}
		//coefficient vector initialisation
		for(int i=0;i<k;i++){
			cin>>num;
			c.push_back(num);
		}
		cin>>n;
		cout<<compute(n)<<endl;
		//for further testcases, clear b and c vector
		b.clear();
		c.clear();
	}
	return 0;
}
