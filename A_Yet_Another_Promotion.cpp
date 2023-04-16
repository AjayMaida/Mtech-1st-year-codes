#include<bits/stdc++.h>
using namespace std;
long long solve(){
    long long a,b;
        cin>>a>>b;
        long long n,m,cost=0;
        cin>>n>>m;
            // cout<<n<<m;
        while(n>=1){
            if(n>=m && (m+1)*b>=m*a){
            cost+=a*m;
            n=n-m-1;
            }else{
                cost=min(a,b)*n;
                // cout<<cost<<"yes";
                // if(n%2!=0){
                //     cost+=min(a,b);
                // }
                return cost;
            }
            // cout<<n<<" "<<cost;
            if(n==0)return cost;
            cost+=b;
            n=n-1;
            // cout<<"\n"<<n<<" "<<cost;
        }
        return cost;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        cout<<solve()<<"\n";
    }
}