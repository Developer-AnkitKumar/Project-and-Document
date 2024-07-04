#include <iostream>
using namespace std;

const int INT_MIN = -1;

typedef struct queue {
  int front, rear;
  int size, max;
  int *arr;
}Queue;

Queue* createQueue(int max) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->max = max;
  queue->front = 0;
  queue->size = 0;
  queue->rear = max - 1;
  queue->arr = (int *)malloc(queue->max * sizeof(int));
  return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
  return queue->size == queue->max;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
  return queue->size == 0;
}

// Add an element to the enqueue
void enqueue(Queue *queue, int data) {
  if (isFull(queue)) {
    cout << "Queue is full\n";
    return;
  }

  queue->rear = (queue->rear + 1) % (queue->max);
  queue->arr[queue->rear] = data;
  queue->size++;
}

// delete element to the dequeue function
int dequeue(Queue *queue){
  if(isEmpty(queue)){
    cout<<"queue is empty";
  }
  int data = queue -> arr[queue -> front];
  queue -> front = (queue -> front + 1)%queue -> max;
   queue->arr[queue->front] = data;
  queue -> size--;
  return data;
}
// Get the front element of the queue
int front(Queue *queue) {
  if (isEmpty(queue)) {
    return INT_MIN;
  }

  return queue->arr[queue->front];
}

// Get the rear element of the queue
int rear(Queue *queue) {
  if (isEmpty(queue)) {
    return INT_MIN;
  }

  return queue->arr[queue->rear];
}

// Display the contents of the queue
void display(Queue *queue) {
  if (isEmpty(queue)) {
    return;
  }

  for (int i = 0; i < queue->size; i++) {
    cout << queue->arr[(queue->front + i) % queue->max] << " ";
  }
  cout << endl;
}

int main() {
  int max, n;
  cin >> max >> n;

  Queue *queue = createQueue(max);

  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;
    enqueue(queue, data);
  }

  display(queue);
  cout<<dequeue(queue)<<endl;
  cout << "Front: " << front(queue) << endl;
  cout<<dequeue(queue)<<endl;

  enqueue(queue, 100);
  display(queue);
  cout << "Rear: " << rear(queue) << endl;
  return 0;
  }

//   const int MAX_SIZE = 100;

//   class Queue{
//     private:
//     int front, rear;
//     int arr[MAX_SIZE];

//     public:
//     Queue(){
//       int front = -1;
//       int rear = -1;
//     }

//     bool isEmpty(){
//         return front == -1 && rear == -1;
//     }

//     bool isFull(){
//       return (rear + 1)%MAX_SIZE == front;
//     }

//     void enqueue(int element){
//       if(isFull()){
//         cout<<"queue is full \n";
//         return;
//       }
//       if(isEmpty()){
//         front = rear = 0;
//       }
//       else{
//         rear = (rear + 1)%MAX_SIZE;
//       }
//       arr[rear] = element;
//       cout<<element<<"\n";
//     }


//     void dequeue(){
//       if(isEmpty()){
//         cout<<"queue is empty \n";
//         return;
//       }
//       int removedElement = arr[front];
//         cout << removedElement << " (dequeue)\n";

//       if(front == rear){
//         front = rear = -1;
//       }
//       else{
//         front = (front + 1)% MAX_SIZE;
//       }
//     }
//     void display(){
//      if(isEmpty()){
//         cout<<"queue is empty \n";
//         return;
//       }
//       int i = front;
//       while(i != rear){
//         cout<<arr[i]<<" ";
//         i = (i + 1)%MAX_SIZE;
//       }
//       cout<<arr[rear]<<endl;
//     }
//   };

//   int main()
//   {
//     Queue queue;
//   int n, element;
//   cout<<"enter a number of element";
//   cin>>n;

//   for (int i = 0; i < n; ++i) {
//         cin >> element;
//         queue.enqueue(element);
//         queue.display();
//     }

//     for (int i = 0; i < n; ++i) {
//          queue.dequeue();
//          queue.display();
//     }
//   return 0;
// }
