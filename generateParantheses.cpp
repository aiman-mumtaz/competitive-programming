#include <iostream>
using namespace std;

void printparanthesis(char *ans,int n, int i, int open, int close){
    if(i==2*n){
        ans[i]='\0';
        cout<<ans<<"\n";
        return;
    }
	if(close<open){
        ans[i] = ')';
        printparanthesis(ans,n,i+1,open,close+1);
    }
    if(open<n){
        ans[i] = '(';
        printparanthesis(ans,n,i+1,open+1,close);
    }
    
    return;
}


int main() {
    int n;  cin>>n;
    char ans[100];
    printparanthesis(ans, n, 0,0,0);
    return 0;
}
