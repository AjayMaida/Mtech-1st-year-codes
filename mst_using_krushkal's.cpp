#include<bits/stdc++.h>
const int N=1e5+6;
std::vector<int> parent(N);
std::vector<int> siz(N);
void make_set(int v){
    parent[v]=v;
    siz[v]=1;
}
//gives you leading element
int find_set(int v){
    if(parent[v]==v)
    return v;
    return parent[v]=find_set(parent[v]);//pathcompresion
}
void union_set(int u,int v){
    int x=find_set(u);
    int y=find_set(v);
    if(x!=y){
        if(siz[x]<siz[y]) //reducing the long chain by adding small disjoin set to beg one
        std::swap(x,y);
        parent[y]=x;
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
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> edges;
    int u,v,w;
    for(int i=0;i<m;i++){
        std::cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    std::sort(edges.begin(),edges.end());
    int cost=0;
    for(auto i: edges){
        int w=i[0];
        int u=i[1];
        int v=i[2];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y)
        continue;
        union_set(u,v);
        std::cout<<u<<" "<<v<<"\n";
        cost+=w;
    }
    std::cout<<cost;
}