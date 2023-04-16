#include<bits/stdc++.h>
using namespace std;
void solve(){
int n;cin>>n;
vector<int> v(n);
bool flag=true;
for(int i=0;i<n;i++){
    cin>>v[i];
    if(v[i]%2!=v[i%2]%2)flag=false;
    else flag=false;
}
if(flag)puts("YES");
else puts("NO");
}
int main(){
int t;
cin>>t;
while(t--){
solve();
}
return 0;
}