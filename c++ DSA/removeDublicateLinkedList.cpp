#include<iostream>
using namespace std;

struct singlyLinkedListNode{  // create a new node
    int data;       // insert data in new node
    singlyLinkedListNode*next;
};

singlyLinkedListNode* removeDublicate(singlyLinkedListNode*head){
    if(head == nullptr || head -> next == nullptr){
        return head;
    }
    singlyLinkedListNode* current = head;   // head node point into cueent node
    while(current != nullptr){
        singlyLinkedListNode*next = current -> next;
        while(next != nullptr && next -> data == current -> data){
            next = next -> next;
        }
        current -> next = next;
        current = current -> next;
    }
    return head;
}
int main(){
    singlyLinkedListNode* head = new singlyLinkedListNode{1};  // insert data in first node point head node(1) and then other operation in serial way
    head -> next = new singlyLinkedListNode{2};
    head->next->next = new singlyLinkedListNode{2};
    head->next->next->next = new singlyLinkedListNode{3};
    head->next->next->next->next = new singlyLinkedListNode{3};
    head->next->next->next->next->next = new singlyLinkedListNode{4};
    
    head = removeDublicate(head);

    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}