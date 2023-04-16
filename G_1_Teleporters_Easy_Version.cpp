#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,c,sum=0;
    cin>>n>>c;
    vector<int> v(n);int i=0;
    for(auto &it:v)cin>>it,it+=1+i,i++;
    sort(v.begin(),v.end());
    i=0;
    for(auto& it:v){
        sum+=it;
        if(sum>c){
            cout<<i<<"\n";
            return ;
        }i++;
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