#include<bits/stdc++.h>
using namespace std;
 void solve(){
   int n;
   cin>>n;
   string s;
   cin>>s;
   int x=0,y=0;
   for(int i=0;i<s[i];i++){
    if(s[i]=='L')x-=1;
    if(s[i]=='R')x+=1;
    if(s[i]=='U')y+=1;
    if(s[i]=='D')y-=1;
    if(x==1 && y==1) {
        cout<<"YES\n";
        return ;
    }
   }
   cout<<"NO\n";

 }
int main(){
    int t;cin>>t;while(t--){
        solve();
    }
}