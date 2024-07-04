#include<iostream>
using namespace std;

struct singlyLinkedListNode{  // create a new node
    int data;       // insert data in new node
    singlyLinkedListNode*next;
};

singlyLinkedListNode* reverseLinkedList(singlyLinkedListNode*head){
  if(head == nullptr || head->next == nullptr){
    return head;
  }

  singlyLinkedListNode* prev = nullptr;
  singlyLinkedListNode* current = head;
  
  while(current != nullptr){
    singlyLinkedListNode* next = current -> next;
    current -> next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

int main()
{
    singlyLinkedListNode* head = new singlyLinkedListNode{1};  // insert data in first node point head node(1) and then other operation in serial way
    head -> next = new singlyLinkedListNode{2};
    head->next->next = new singlyLinkedListNode{3};
    head->next->next->next = new singlyLinkedListNode{4};
    head->next->next->next->next = new singlyLinkedListNode{5};
    
    head = reverseLinkedList(head);

    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}