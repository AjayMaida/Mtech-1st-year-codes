#include<bits/stdc++.h>
using namespace std;
set<vector<int>> res;
void subseq(vector<int> &a, vector<int> v,int i,int &ans){
    if(i>=a.size()){
        cout<<"{";
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i<v.size()-1)cout<<",";
        }
        cout<<"}"<<endl;
        return ;
    }
    subseq(a,v,i+1,ans);
    if(v.size()==0)
    v.push_back(a[i]);
    else if(a[i]>=v[v.size()-1]){
        v.push_back(a[i]);
        res.insert(v);
        ans++;
        cout<<ans<<endl;
    }
    subseq(a,v,i+1,ans);
}
int main(){
    int n;
    int ans=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> v;
    subseq(a,v,0,ans);
    cout<<ans<<endl;

    for(auto it:res){
        cout<<"[";for(auto i:it)cout<<i<<" ";cout<<"]";
        cout<<endl;
    }
}