#include<bits/stdc++.h>
std::vector<std::vector<int>> a(10,std::vector<int>(10,0));
int arr[10][10];
int main(){
    std::cout<<"simple array:\n";
for(auto i=0;i<10;i++){
    for(auto j=0;j<10;j++){
        std::cout<<arr[i][j];
    }std::cout<<"\n";
}
std::cout<<"vector:\n";
for(auto it:a){
    for(auto i:it)
    {
        std::cout<<i;
    }std::cout<<"\n";
}
std::cout<<"using simple loop to print vector\n";
for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
        std::cout<<a[i][j];
    }std::cout<<"\n";
}
std::cout<<"hello";
}