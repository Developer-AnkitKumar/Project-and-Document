#include <iostream>
 using namespace std;

 class stack  // these are the both combine function are class and public:
  {
   int capacity;
   int top;
   int* array;
public: 
  stack(int capacity){
    this -> capacity = capacity;
    array = new int[capacity];
    top =-1;
}

int size(){
    return top +1;
}

bool isEmpty(){
    return top == -1;
} 


bool isFull(){
    return top +1 == capacity;
}

void push(int capacity ){
    if(isFull()){
        cout<<"stack is overflow"<<endl;
        return;
    }
    top++;
    array[top] = capacity;
}

int peek(){
    if(isEmpty()){
        cout<<"stack is empty"<< endl;
        return -1;
    }
    return array[top];
}

int pop(){
    if(isEmpty()){
        cout<<"stack is undeflow"<< endl;
        return -1;
    }
    return array[top--];
 }
};

int main(){
    int capacity, n;
    cin>>capacity>>n;
    stack * st = new stack(capacity);
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        st -> push(ele);
    }
    cout<<"top of the stack = "<<st -> peek()<<"\n";
    cout<<"size of  stack = "<<st -> size()<<"\n";

    cout<<"popping all the element:\n";
   while (!st->isEmpty()) {
    cout << st->pop() << " ";
  }
    cout<<endl;
    delete st;
    return 0;
}
