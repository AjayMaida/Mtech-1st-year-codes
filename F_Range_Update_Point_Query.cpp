#include<bits/stdc++.h>
using namespace std;
int getSum(int n)
    {
        int sum;
        for (sum = 0; n > 0; sum += n % 10, n /= 10);
        return sum;
    }
 void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    set<int> st;
    st.insert(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]>9)st.insert(i);
    }
    while(q--){
        int x,l,r;
        cin>>x;
        if(x==1){
            cin>>l>>r;
            l--,r--;
            auto it=st.lower_bound(l);
            while(it!=st.end() && *it<=r){
                v[*it]=getSum(v[*it]);
                if(v[*it]<=9)st.erase(*it);
                it=st.lower_bound(*it+1);
            }
        }
        else{
            int i;cin>>i;i--;
            cout<<v[i]<<"\n";
        }
    }
 }
int main(){
    int t;cin>>t;while(t--){
        solve();
    }
}