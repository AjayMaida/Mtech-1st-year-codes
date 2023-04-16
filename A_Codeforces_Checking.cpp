#include<bits/stdc++.h>
using namespace std;
int main(){
    int test_case;
    cin>>test_case;
    while(test_case--){
        string s="codforces";
        char ch;
        cin>>ch;
        if(s.find(ch)!= string::npos)cout<<"yes\n";
        else cout<<"no\n";
    }
}