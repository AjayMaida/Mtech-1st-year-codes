#include<bits/stdc++.h>

bool comp(int a, int b){
    return a<b;
}
bool comp1(int a,int b){
    return a>b;
}

void demo_funtion_pointer(bool(*func_pointer)(int ,int)){
    std::cout<<func_pointer(2,10)<<"\n";
}

int main(void){
    std::cout<<&comp<<" "<<comp1<<"\n";
    demo_funtion_pointer(comp);
    demo_funtion_pointer(comp1);
}