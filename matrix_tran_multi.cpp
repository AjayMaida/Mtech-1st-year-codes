#include<bits/stdc++.h>
using namespace std;
int main(){

    int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    vector<vector<int>> ans(3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int sum=0;
            for(int k=0;k<4;k++){
                sum+=arr[i][k]*arr[j][k];
            }
                ans[i].push_back(sum);
        }
    }
    for(auto &it:ans){
        for(auto& i:it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}