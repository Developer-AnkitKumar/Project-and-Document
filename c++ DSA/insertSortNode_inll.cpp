#include <iostream>
using namespace std;

struct SinglyLinkedListNode {
  int data;
  SinglyLinkedListNode *next;
};

SinglyLinkedListNode *insertSortNode(SinglyLinkedListNode *head, int data, int pos) {
  SinglyLinkedListNode *newNode = new SinglyLinkedListNode();
  newNode->data = data;
  newNode->next = nullptr;

  if (pos == 1) {
    newNode->next = head;
    head = newNode;
    return head;
  }

  SinglyLinkedListNode *current = head;
  SinglyLinkedListNode *prev = nullptr;
  int count = 1;

  while (current != nullptr && count < pos) {
    prev = current;
    current = current->next;
    count++;
  }

  if (prev == nullptr) {
    return newNode;
  }

  prev->next = newNode;
  newNode->next = current;
  return head;
}

void printList(SinglyLinkedListNode *head) {
  while (head != nullptr) {
    std::cout << head->data << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  SinglyLinkedListNode *head = nullptr;

  head = insertSortNode(head, 10, 2);  // print the element by denoted the index value
  head = insertSortNode(head, 5, 1);
  head = insertSortNode(head, 20, 3);
  head = insertSortNode(head, 3, 1);

  printList(head);

  return 0;
}
