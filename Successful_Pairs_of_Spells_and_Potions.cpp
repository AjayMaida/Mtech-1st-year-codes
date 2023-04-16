#include<bits/stdc++.h>
using namespace std;

class Solution {
        vector<int> ans;
        vector<vector<int>> v;
        int suc;
public:
    int fun1(vector<int>& spells, vector<int>& potions,int mid){
        int ans=0;
        for(int i=0;i<potions.size()-1;i++){
            if(spells[mid]*potions[i]>=suc)ans++;
        }
        return ans;
    }
    void fun(vector<int>& spells, vector<int>& potions, int st, int en){
        if(st>en)return ;
        int mid=st+(en-st)/2;
        int num_pair=fun1(spells,potions,mid);
        if(num_pair==0)
        {
            for(int i=st;i<=mid;i++){
            ans[v[i][1]]=0;
        }
        fun(spells,potions,mid+1,en);
        return;
        }
        if(num_pair==spells.size()){
            for(int i=mid;i<=en;i++){
                ans[v[i][1]]=num_pair;
            }
            fun(spells,potions,st,mid-1);
            return ;
        }
        ans[v[mid][1]]=num_pair;
        fun(spells,potions,st,mid-1);
        fun(spells,potions,mid+1,en);

    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        int suc=success;
        for(int i=0;i<n;i++){
            v.push_back({spells[i],i});
        }
        sort(v.begin(),v.end());
        fun(spells,potions,0,n-1);
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto& it:v)cin>>it;
    int m;
    cin>>m;
    vector<int> v1(m);
    for(auto &it :v1)cin>>it;
    vector<int> ans;
    Solution ob;
    long long  suc;
    cin>>suc;
    ans=ob.successfulPairs(v,v1,suc);
    for(const auto &it:ans)cout<<it<<" ";
    return 0;
}
