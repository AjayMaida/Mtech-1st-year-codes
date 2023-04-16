#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    unordered_map<char,Node*> children;
    bool isterminal=false;
    Node(){}
};

class Trie{
    public:
    Trie(){}
    Node* root=new Node;
    void insert(string& word){
        Node* node=root;
        for(auto ch:word){
            if(!node->children.count(ch)){
                node->children[ch]=new Node;
            // cout<<ch<<" ";
            }
                node=node->children[ch];
        }
        node->isterminal=true;
    }
    
    bool searcH(string& word){
        Node* node=root;
        for(auto ch:word){
            if(!node->children.count(ch)) return false;
            cout<<ch<<" ";
            node=node->children.at(ch);
        }
        return node->isterminal;
    }
};
int main(){
    Trie rooT;
    string ss="ajay";
    rooT.insert(ss);
    // 
    // vector<string> v={"ajay","apple","app","application","appli","ajax","aj","aja"};
    // for(int i=0;i<v.size();i++)
    // rooT.insert(v[i]);
    // cout<<"hello";
    string s="aja";
    cout<<rooT.searcH(s);
    return 0;
}