#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(auto &it:v)
        cin>>it;
        int ans=0;
        sort(v.begin(),v.end());
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
            ans+=v[i];
            cout<<ans<<" ";
        }cout<<"\n";
        for(auto it:v)
        cout<<it<<" ";
        cout<<ans<<"\n";
    }
}