#include<bits/stdc++.h>
using namespace std;
 void solve(){
    int n;cin>>n;
    vector<int> v(n);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    for(int i=0;i<n;i++){
        mp[v[i]]++;
        if(mp[v[i]]>=3){
            cout<<v[i]<<endl;
            return ;
        }
    }
    cout<<-1<<endl;
}
int main(){
int t;
cin>>t;
while(t--){
solve();
}
return 0;
}