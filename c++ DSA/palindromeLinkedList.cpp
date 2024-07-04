// #include<iostream>
//  using namespace std;

// struct SinglyLinkedListNode{
//     int data;
//     SinglyLinkedListNode* next;
// };

// bool palindromeList(SinglyLinkedListNode* head){
//     if(head == nullptr || head -> next == nullptr){
//         return true;
//     }

//     SinglyLinkedListNode* slow = head;
//     SinglyLinkedListNode* fast = head;

//     while(fast != nullptr && fast -> next != nullptr){
//         slow = slow -> next;
//         fast = fast -> next -> next;
//     }
//     SinglyLinkedListNode* secondHalf =slow;
//     SinglyLinkedListNode* firstHalf = head;
//     bool palindrome = true;

//     while(secondHalf){
//         if(secondHalf -> data != firstHalf -> data ){
//             palindrome = false;
//             break;
//         }
//         firstHalf = firstHalf -> next;
//         secondHalf = secondHalf -> next;
//     }
//     return palindrome;
// }
// int main(){
//     Node *head = new Node();
//   head->data = 1;
//   head->next = new Node();
//   head->next->data = 2;
//   head->next->next = new Node();
//   head->next->next->data = 1;
    
//     if(palindromeList(head)){
//         cout<<"the linked list is palindrome:"<< endl;

//     }
//     else{
//         cout<<"the linked list is not palindrome:"<<endl;
//     }
//     return 0;
// }

#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
  int data;
 Node* next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

bool palindromeList(Node* head) {
  stack<int> intStack;
  Node* current = head;

  while (current != nullptr) {
    intStack.push(current->data);
    current = current->next;
  }

  current = head;
  while (!intStack.empty()) {
    if (current->data != intStack.top()) {
      return false;
    }

    intStack.pop();
    current = current->next;
  }

  return true;
}

int main() {
  Node* head = new Node(-1);
  head->next = new Node(2);
  head->next->next = new Node(1);

  if(palindromeList(head)) {
    cout << "Linked list is palindrome." << endl;
  } else {
    cout << "Linked list is not palindrome." << endl;
  }

  return 0;
}
