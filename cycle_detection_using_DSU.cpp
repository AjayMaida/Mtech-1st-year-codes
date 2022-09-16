#include<bits/stdc++.h>
#define N (int)1e5+6
std::vector<int> parent(N);
std::vector<int> siz(N);
void  make_set(int v){
    parent[v]=v;
    siz[v]=1;
}
int find_set(int x){
    if(parent[x]==x)
    return x;
    return parent[x]=find_set(parent[x]);
}
void union_set(int u,int v){
    int x=find_set(u);
    int y=find_set(v);
    if(x!=y)
    {
        if(siz[x]<siz[y])
        std::swap(x,y);
        parent[y]=x;//generalizing so that we don't have to handle different case
        siz[x]+=siz[y];
    }
}
bool cycle(std::vector<std::vector<int>> edges){
    for(auto i: edges){
        int x=i[0];
        int y=i[1];
        int a=find_set(x);
        int b=find_set(y);
        if(a==b)
        return true;
        union_set(x,y);
    }
    return false;
}
int main(){
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<N;i++){
        make_set(i);
    }
    std::vector<std::vector<int>> edges;
    int u,v;
    for(int i=0;i<m;i++){
        std::cin>>u>>v;
        edges.push_back({u,v});
    }
    printf("%d",cycle(edges));
}