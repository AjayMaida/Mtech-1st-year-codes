#include<bits/stdc++.h>
using namespace std;
int main(){
    int test_case;
    cin>>test_case;
    while(test_case--){
        int n;cin>>n;
        int a=0,b=0;
        vector<int> v;
        int sum=0;
        for(int i=1;sum<=n;i++,sum+=i){
            v.push_back(i);
        }
        v.push_back(n-v[v.back()]);
        for(const auto & it: v)cout<<it<<" ";
    }
}