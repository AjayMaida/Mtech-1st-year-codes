#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,c,sum=0;
    cin>>n>>c;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
            int x;cin>>x;
        if(i<n/2){
            v.push_back({x+1+i,i+1});
        }else{
            // cout<<x+n-i<<" ";
            v.push_back({x+n-i,i+1});
        }
    }
    // sort(v.begin(),v.begin()+n/2);
    sort(v.begin()+1,v.end());
    // for(auto it:v)cout<<it<<" ";
    if(v[0].second>(n/2)){
        v[0].first=v[0].first-(n-v[0].second+1)+v[0].second;
    }
    int i=0;
    for(int i=0;i<n;i++){
        sum+=v[i].first;
        if(sum>c){
            cout<<i<<"\n";
            return ;
        }
    }
    cout<<n<<"\n";

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}