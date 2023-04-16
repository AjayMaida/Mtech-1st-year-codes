#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;while(t--){
        int n,m;
        cin>>n>>m;
        vector<string> v;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=0;
                for(int k=0;k<m;k++){
                    int temp_diff=abs(v[i][k]-v[j][k]);
                    if(temp_diff==26) diff+=1;
                    else diff+=temp_diff;
                }
                mn=min(mn,diff);
            }
        }
        cout<<mn<<endl;
    }
}