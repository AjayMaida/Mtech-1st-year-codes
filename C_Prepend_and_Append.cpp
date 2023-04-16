#include<bits/stdc++.h>
using namespace std;
 void solve(){
     int n;
     cin>>n;
     string s;
     cin>>s;
     if(n==1){
         cout<<1<<"\n";
         return ;
     }
     if(s[0]==s[n-1]){
         cout<<n<<"\n";
         return ;
     }
     int k=0,i=0,j=n-1;
     while(i!=j && i<j){
         if(s[i]!=s[j]){
             k++;
         }
         else break;
         i++;j--;

     }
     cout<<(n-k*2)<<"\n";
 }
int main(){
    int t;cin>>t;while(t--){
        solve();
    }
}