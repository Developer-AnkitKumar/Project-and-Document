 #include <iostream>
 using namespace std;

 struct stack {
   int capacity;
  int top;
  // @brief 
 int* array;
};

 stack* initializerStack(int capacity) {
   stack* s = (stack*)malloc(sizeof(stack));
   s -> capacity = capacity;
   s -> top = -1;
   s->array = new int[s->capacity];

   return s;
 }

 int size(stack* s) {
   return s -> top + 1;
 }

 int isEmpty(stack* s) {
   return s -> top == -1;
 }

 int isFull(stack* s) {
   return s -> top == s -> capacity - 1;
 }

 void push(stack*& s, int element) {
   if (isFull(s)) {
     cout << "Stack overflow" << endl;
     return;
   }

  s -> top = s -> top +1;   //++s.top
  s -> array[s -> top] = element;
}

int pop(stack*& s) {
  if (isEmpty(s)) {
    cout << "Stack underflow" << endl;
    return -1;
  }

  int element = s -> array[s -> top];
  s -> top = s -> top -1;   //--s.top

  return element;
}

int peek(stack* s) {
  if (isEmpty(s)) {
    cout << "Stack empty" << endl;
    return -1;
  }

  return s -> array[s -> top];
}

void display(stack* s) {
  if(isEmpty(s)) {
    cout << "Stack empty" << endl;
    return;
  }

  for (int i = s -> top; i >= 0; i--) {
    cout << s -> array[i] << " ";
  }

  cout << endl;
}

int main() {
  stack* s = initializerStack(10);

  push(s, 1);
  push(s, 2);
  push(s, 3);

  display(s);

  cout << "Popped element: " << pop(s) << endl;

  display(s);

  return 0;
}