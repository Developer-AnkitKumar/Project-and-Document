#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* addOneToList(node* head)
{
    if(!head){
        return head;
    }
   
    node* current = head;
    int carry = 1;

    while (current) {
        int sum = current->data + carry;
        current->data = sum % 10;  // using mod. operator 10 mod 10 = 0: 10 mod 9 = 1:
        carry = sum / 10;   // last mai ydi element koi nhi hai to only 1 return ho jaye ga;

        if (!carry) {
            break;
        }

        current = current ->next;
    }
    
    // If there's a carry left, add a new node at the beginning
    if (carry) {
        node* newNode = new node{carry, head};
        head = newNode;
    }
    return head;
}
node* display(node* head)
{
    node* current;
    current = head;
    while(current != NULL){
       cout<<current -> data<<" ";
        current = current -> next;
    }
}
int main() {
    // Create a sample linked list with nodes containing data 9, 9, 9
    node* head = new node{9, NULL};
    head -> next = new node{9, NULL};
    head -> next -> next = new node{9, NULL};

    cout << "Original list: ";
    display(head);

    head = addOneToList(head);

    cout << "\nList after adding one: ";
    display(head);

    return 0;
}