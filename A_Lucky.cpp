#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        // int n;
        // cin>>n;
        // int temp=n;
        // int count=0;
        // while(temp){
        //     count++;
        //     temp=temp/10;
        // }
        // string s="";
        // count=6-count;
        // // cout<<count;
        // while(count-->0){
        //     s+="0";
        // }
        // s+=to_string(n);
        // int sum=0,sum1=0;
        // for(int i=0;i<3;i++){
        //     int t=s[i]-'0';
        //     // cout<<t<<" ";
        //     sum+=t;
        //     int t1=s[s.size()-i-1]-'0';
        //     sum1+=t1;
        // }
        // // cout<<"\n"<<sum<<" "<<sum1;
        // if(sum!=sum1)cout<<"NO\n";
        // else cout<<"YES\n";
        string s;
        cin>>s;
        if(s[0]+s[1]+s[2]==s[3]+s[4]+s[5]) cout<<"YES\n";else cout<<"NO\n";
    }
}