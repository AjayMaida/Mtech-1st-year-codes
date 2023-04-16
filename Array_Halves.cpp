#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    cin >> n;
    vector<int> v(n * 2);
    for (auto &it : v)
        cin >> it;
    int c=0,c1=0,c2=0;
    vector<int> v1,v2;
    for(int i=0;i<n;i++){
        if(v[i]>n){
            v1.push_back(i);
        }
        if(v[i+n]<n+1){
            v2.push_back(i+n);
        }
    }
    // for(auto it:v1)cout<<it<<" ";
    // cout<<endl;
    // for(auto it:v2)cout<<it<<" ";
    // cout<<endl;
    for(int i=0;i<v1.size();i++){
       c+=(n-1-v1[i])-c1;c1++; 
    }
    for(int i=0;i<v2.size();i++){
        c+=(v2[i]-n)-c2;c2++;
    }
    c+=v1.size()*v2.size();
    return c;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}