#include<bits/stdc++.h>
using namespace std;
long long int solve(){
int n;cin>>n;
vector<int> v(n);
int mx=INT_MIN;
long long sum=0;
for(int i=0;i<n;i++){
    cin>>v[i];
    mx=max(v[i],mx);
    sum+=v[i];
}
if(v[0]==mx) return v[0];
double t=(double)sum/n;
return ceil(t);
}
int main(){
int t;
cin>>t;
while(t--){
cout<<solve()<<endl;
}
return 0;
}