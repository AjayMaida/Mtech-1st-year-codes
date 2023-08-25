#include <bits/stdc++.h>

template<class TT>
class Node{
    public:
    TT data;
    Node* nxt;
    Node(TT data):data(data),nxt(NULL){}
};

template<class TT>
class LinkedList{
    public:
    Node<TT>* head;
    LinkedList():head(nullptr){}
    void display(){
        Node<TT>* curr=head;
        while(curr){
            std::cout<<curr->data<<"->";
            curr=curr->nxt;
        }
        std::cout<<"NULL\n";
    }
    void insertAtHead(TT data){
        Node<TT>* new_node=new Node<TT>(data);
        new_node->nxt=head;
        head=new_node;
    }
};

void reverseList(Node<int>* /*very important to put '&' here*/ &head){
    Node<int>* curr=head,*pre=NULL,*next;
    std::cout<<head->data<<"\n";
    while(curr){
        next=curr->nxt;
        curr->nxt=pre;
        pre=curr;
        curr=next;
    }
    head=pre;
}

int main(){
    int n;
    std::cin>>n;
    std::vector<int> v(n);
    for(auto & el:v)std::cin>>el;
    LinkedList<int>* List=new LinkedList<int>();
    for(int el:v){
        List->insertAtHead(el);
    }
    List->display();
    reverseList(List->head);
    List->display();
}