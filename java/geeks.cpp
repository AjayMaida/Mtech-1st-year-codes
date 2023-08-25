#include<bits/stdc++.h>
using namespace std;

//User function Template for C++
class Solution{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
      // code here
          cout<<"hello\n";
      vector<vector<int>> v;
      for(int i=0;i<N;i++){
          v.push_back({A[i],i});
      }
      sort(v.begin(),v.end(),greater<int>());
      vector<int> result;
      for(int i=0;i<Queries.size();i++){
          int c=Queries[i][0];
          int def_n=Queries[i][1];
          unordered_map<int,int> mp;
          for(int k=0;k<def_n;k++){
              
              mp[Queries[i][k+2]-1]++;
          }
          int ans=0;
          int j=0;
          while(c>0 && j<N){
              if(mp.count(v[j][1])!=0){
                  j++;
                  continue;
              }
              if(v[j][0]>c)break;
              c-=v[j][0];
              ans++;
              j++;
          }
          result.push_back(ans);
      }
      return result;
  }
};
int main(){
    int t=1;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>A(N);
        for(auto &it:A)cin>>it;
        int Q;cin>>Q;
        vector<vector<int>>Queries(Q);
        for(int i=0;i<Q;i++){
            int x,y;
            cin>>x>>y;
            Queries[i].push_back(x);
            Queries[i].push_back(y);
            for(int j=0;j<Queries[i][1];j++){
                cin>>x;
                Queries[i].push_back(x);
            }
        }
        Solution obj;
        auto ans=obj.maximumToys(N,A,Q,Queries);
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}