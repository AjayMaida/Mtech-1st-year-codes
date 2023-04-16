#include<bits/stdc++.h>
using namespace std;
 void solve(){
    int n;cin>>n;
    vector<int> v(n),p(n,0);
    long long sum=0;
    long long tt=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=abs(v[i]);
        if(v[i]<0)tt++;
    }
    for(int i=0;i<n;i++){
        if(v[i]<0) v[i]=abs(v[i]);
    }
    if(tt%2==0){
        cout<<sum<<"\n";
        return;
    }
    long long m=*min_element(v.begin(),v.end());
    cout<<sum-2*m<<"\n";
 }
int main(){
    int t;cin>>t;while(t--){
        solve();
    }
}