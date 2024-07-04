#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* MergeSortedList(node* h1, node* h2)
{
  if(h1 == NULL){
    return h2;
  }
  if(h2 == NULL){
    return h1;
  }
  if(h1 -> data > h2 -> data){
    node* temp = h2;
    h1 = h2;
    h2 = temp;
  }

  node* result = h1;
  while(h1 && h2){
    node* temp = h1;
    while(h1 && h1 -> data <= h2 -> data){
        temp = h1;
        h1 = h1 -> next;
    }
    temp -> next = h2;
    if(h1 == NULL){
        break;
    }
    temp = h2;
    while(h2 && h2 -> data <= h1 -> data){
        temp = h2;
        h2 = h2 -> next;
    }
    temp -> next = h1;
  }
   return result;
}

int main() {
  // Create two sorted linked lists
  node* h1 = NULL;
  node* h2 = NULL;

  node* n1 = new node;
  n1->data = 1;
  h1 = n1;

  node* n2 = new node;
  n2->data = 2;
  n1->next = n2;

  node* n4 = new node;
  n4->data = 4;
  n2->next = n4;

  node* n3 = new node;
  n3->data = 3;
  h2 = n3;

  node* n5 = new node;
  n5->data = 5;
  n3->next = n5;

  // Merge the two sorted linked lists
  node* mergedList = MergeSortedList(h1, h2);

  // Print the merged list
  node* temp = mergedList;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  return 0;
}