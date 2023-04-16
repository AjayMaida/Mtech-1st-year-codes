#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;while(t--){
        int arr[4];
        for(int i=0;i<4;i++){
            cin>>arr[i];
        }
        int timur=arr[0];
        sort(arr,arr+4,greater<int>());
        for(int i=0;i<4;i++){
            if(arr[i]==timur){
                cout<<i<<endl;
                break;
            }
        }
    }
}