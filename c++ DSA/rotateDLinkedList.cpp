#include<iostream>
using namespace std;

struct DllNode{
  int data;
  DllNode*next;
  DllNode*prev;
};

DllNode*rotateDoublyList(DllNode *head, int k)
{
    if(k == 0 || !head){
        return head;
    }

    DllNode* current = head;
    int len = 1;
    while(current -> next){
        len++;
        current = current -> next;
    }
    k = k % len;
    if(k == 0){
        return head;
    }
    DllNode* newCurrent = head;
    for(int i = 1; i < len-k; i++){
        newCurrent = newCurrent -> next;
    }
    DllNode* newHead = newCurrent -> next;
    newCurrent -> next = nullptr;
    current -> next = head;
    head -> prev = current;

     return newHead;
}
void printList(DllNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    DllNode* head = new DllNode{1, nullptr, nullptr};
    head->next = new DllNode{2, nullptr, head};
    head->next->next = new DllNode{3, nullptr, head->next};
    head->next->next->next = new DllNode{4, nullptr, head->next->next};
    head->next->next->next->next = new DllNode{5, nullptr, head->next->next->next};

    cout << "Original list: ";
    printList(head);

    int k = 3;
    head = rotateDoublyList(head, k);

    cout << "Rotated list: ";
    printList(head);

    return 0;
}

