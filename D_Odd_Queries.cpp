#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        vector<int>v(n+1);
        v[0]=0;
        for(int i=0;i<n;i++)cin>>v[i];
        vector<int> p(n+1);
        p[0]=0;
        for(int i=1;i<=n;i++){
            p[i]=v[i-1]+p[i-1];
        }
        // for(auto it:v)cout<<it<<" ";
        // cout<<"\n";
        // for(auto it:p)cout<<it<<" ";
        // cout<<"\n";
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            int diff=p[r]-p[l-1]-(r-l+1)*k;
            // cout<<p[r]<<" "<<p[l-1]<<"\n";
            // cout<<diff<<" "<<p[n]<<" "<<p[n]-diff<<"\n";
            if((p[n]-diff)%2!=0)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}