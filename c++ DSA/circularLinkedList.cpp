#include<iostream>
using namespace std;

struct node   //create a new linked list node and insert a data and next in this node
{
    int data;
    node* next;
};
node* head = NULL;
node* tail = NULL;

void insertAtBeginning(int data) {
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

void insertAtEnd(int data)
{
   node* newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail -> next = newNode;
    tail = newNode;
    newNode -> next = head;
}

void insertAtPos(int data, int pos)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = head;
        return;
    }

    node* temp = head;
    int count = 1;

    while (count < pos) {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == tail) {
        tail = newNode;
    }
    if(temp -> next != NULL){
    tail -> next = newNode;
    tail = newNode;
    tail -> next = head;
    return;
}
}

void display()
{
  node* temp ;
  temp = head;
  do {
    cout << temp->data << " ";
    cout<<temp -> next<<"\n";
    temp = temp->next;
  } while (temp != head);
  cout << endl;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
   int n;
   cin>>n;
   int data;

   for(int i = 0; i < n; i++){
    cin>>data;
    insertAtBeginning(data);
   }
   cout<<"insertAtBeginning:";
   display();
   cout<<"\n";
   head = NULL;
   tail = NULL;

   for(int i = 0; i < n; i++){
    cin>>data;
    insertAtEnd(data);
   }
   cout<<"insertAtEnd:";
   display();
   cout<<"\n";

   int pos;
   cin>>pos;
   cin>>data;
   insertAtPos(data, pos);
   cout<<"insertAtPos:"<<pos<<":";
   display();
   cout<<"\n";
   head = NULL;
   tail = NULL;
   }
   return 0;
}