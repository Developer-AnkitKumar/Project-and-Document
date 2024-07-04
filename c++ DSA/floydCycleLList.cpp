#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class soluction{
    public:
    bool  detectNode(node* head){
        node* slow = head;
        node* fast = head;

        while(slow -> next != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast){
               return true;
            }
             else{
            return false;
        }
     }
       
    }
};

int main()
{
    node* head = NULL;

    node*n1 = new node;
    n1 -> data = 1;
    head = n1;

    node*n2 = new node;
    n2 -> data = 2;
    n1 -> next = n2;

    node*n3 = new node;
    n3 -> data = 3;
    n2 -> next = n3;

    node*n4 = new node;
    n4 -> data = 4;
    n3 -> next = n4;

    n4 -> next = n2; // Create a cycle by pointing n4 back to n2

    soluction sol;
    bool dectLoop = sol.detectNode(head);
    if(dectLoop){
        cout<<"cycle dected:";
    }
    else{
        cout<<"cycle not dected:";
    }
    return 0;
}