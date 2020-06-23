#include<iostream>
#include<set>
#include<cstring>
using namespace std;

void permute(char *a, int i, set<string> &s){
	if(a[i] == '\0'){
		string t(a);
		s.insert(t);
		return;
	}
	for(int j=i;a[j]!='\0';j++){
		swap(a[i],a[j]);
		permute(a,i+1,s);
		swap(a[j],a[i]);
	}
}

int main(){
	char a[100];	cin>>a;
	set<string> s;
	permute(a,0,s);
	for(auto w:s){
		cout<<w<<'\n';
	}
	return 0;
}
