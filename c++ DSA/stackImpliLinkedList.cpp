#include <iostream>
 using namespace std;

struct node
 {
    int data;
    struct node* next;
 };
 node* head = NULL;
 int size = 0;

 void push(int data){
    node* newNode = (node*)malloc(sizeof(node));
    if(!newNode){
        cout<<"heap size overflow\n";
        return;
    }
        newNode -> data = data;
        newNode -> next = head;
        head = newNode;
        size++;
 }

 int isEmpty(){
    return head == NULL;
 }

 int Peek()
 {
    if(isEmpty()){
        cout<<"stack is empty\n";
        return -1;
    }
    return head -> data;
 }

 int pop(){
    node* temp;
    if(head == NULL){
       cout<<"stack is underflow\n";
       return -1;
    }
    int element = head -> data;
    temp = head;
    head = head -> next;
    size--;
    free(temp);
    return element;
 }

 int sizeFunction(){
    return size;
 }

 int main(){
    int  n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        push(ele);
    }
    cout<<"top of the stack is:"<<Peek()<<"\n";
    cout<<"size of  stack is: "<<sizeFunction()<<"\n";

    cout<<"popping all the element:\n"; 
    for(int i = 0; i < n; i++){
        cout<<pop()<<"\n";
    }
    cout<<"size of stack is: "<<sizeFunction()<<"\n";
    return 0;
}