#include<iostream>
using namespace std;

struct node   //create a new linked list node and insert a data and next in this node
{
    int data;
    node* next;
};
// void insertAtBeginning(node*& head, int data) {
//   node* newNode = new node;
//   newNode->data = data;

//   if (head == nullptr) {
//     newNode->next = newNode;
//     head = newNode;
//     return;
//   }

//   newNode->next = head;

//   node* temp = head;
//   while (temp->next != head) {
//     temp = temp->next;
//   }

//   temp->next = newNode;
//   head = newNode;
// }

node* head = nullptr;
node* tail = nullptr;
void insertAtBeginning(node*& head, int data) {
    node* newNode = (node*)malloc(sizeof(node));  // Create a new node using malloc
    newNode->data = data;  // Set the data of the new node
    newNode->next = NULL;  // Set the next pointer of the new node to NULL

    if (head == NULL) {  // If the list is empty, make the new node both head and tail
        head = newNode;
        tail = newNode;
        tail->next = head;  // Make the tail's next pointer point to the head
        return;
    }

    newNode->next = head;  
    head = newNode;  
    tail->next = head;  
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
  node* head = nullptr;

  insertAtBeginning(head, 10);
  insertAtBeginning(head, 20);
  insertAtBeginning(head, 30);

  printList(head);

  return 0;
}