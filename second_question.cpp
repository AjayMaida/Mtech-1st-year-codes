#include<bits/stdc++.h>
using namespace std;
class lisT{
    public:
    int data;
    lisT* next;

    lisT(int x){
        data=x;
        next=nullptr;
    }
};

 void creatList(lisT* head, int x){
    lisT* temp=new lisT(x);
    lisT* tra=head;
    while(tra->next){
        tra=tra->next;
    }
    tra->next=temp;
    // delete(temp);
 }
 void displaY(lisT* head){
    lisT* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
 }
bool hasLoop(lisT* head) {
    lisT* slow = head;
    lisT* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}
int main(){ 
    lisT* head=new lisT(2);
    for(int i=0;i<10;i++){
        creatList(head,i);
    }
    displaY(head);

    if(hasLoop(head))cout<<"\nyes, there is a cycle in it\n";
    else cout<<"\nNo cycle is present\n";
}