
#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,A[10000];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)
		cin>>A[i];
		sort(A+1,A+n+1);
		m=unique(A+1,A+n+1)-A-1;
		cout<<n-((n-m+1)/2)*2<<endl;
	}
}
