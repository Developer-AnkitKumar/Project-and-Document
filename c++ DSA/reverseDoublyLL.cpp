#include<iostream>
using namespace std;

struct node   //create a new linked list node and insert a data and next in this node
{
    int data;
    node* next;
    node* prev;
};
void reverse(node*& head)   //using a doubly  reverse linkedList:
{
    node* prev = NULL;
    node* current = head;

    // while(current != NULL){
    //   prev = current -> next;
    //   current -> prev = current -> next;
    //   current -> next = prev;
    //   current = current -> prev;
    // }
    // head = prev;
    while (current != NULL) {
    node* next = current->next;

    current->next = prev;
    current->prev = next;

    prev = current;
    current = next;
  }

  head = prev;
}

void printList(node* head)
 {
  if (head == nullptr) {
    cout << "List is empty" << endl;
    return;
  }

  node* temp = head;
  do {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != head);
  cout << endl;
}

int main() {
  node* head = NULL;

  // Create a circular doubly linked list with nodes 1, 2, 3, 4
  node* n1 = new node;
  n1->data = 1;
  head = n1;

  node* n2 = new node;
  n2->data = 2;
  n1->next = n2;
  n2->prev = n1;

  node* n3 = new node;
  n3->data = 3;
  n2->next = n3;
  n3->prev = n2;

  node* n4 = new node;
  n4->data = 4;
  n3->next = n4;
  n4->prev = n3;
  n4->next = n1;
  n1->prev = n4;

  cout << "Original list: ";
  printList(head);

  reverse(head);

  cout << "Reversed list: ";
  printList(head);

  return 0;
}