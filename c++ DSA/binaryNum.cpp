#include<iostream>
#include <queue>
using namespace std;

void generateBinarynumber(int N){
    queue<string>binaryQueue;
    binaryQueue.push("1");

    for(int i = 1; i<N; i++){
        string currentBinary = binaryQueue.front();
        binaryQueue.pop();

        cout<<"currentBinary"<<" ";

        binaryQueue.push(currentBinary + "0");
        binaryQueue.push(currentBinary + "1");
    }
    cout<<endl;
}

int main()
{
    int T;
    cout<<"enter a number of test case :";
    cin>>T;

    for(int t = 0; t<T; t++){
        int N;
        cout<<"enter a number of N"<<t + 1<<": ";
        cin>>N;

    cout<<"binary representation of a number feom 1 to"<<N<<":";
    generateBinarynumber(N);
    }
    return 0;
}

// void decimalTobinary(int decimalNumber){
//     int binary[32]; //32-bit binary representation rule;

//     int index = 0;

//     while(decimalNumber > 0){
//          binary[index++] = decimalNumber % 2; //module is identify the minimum limit in the decimal number
//          decimalNumber = decimalNumber / 2;
//     }
//     for(int i = index - 1; i >= 0; i--){
//         cout<<binary[i];
//     }
//     cout<<endl;
// }

// int main()
// {
//     int decimalNumber;
//     cout<<"enter a decimal number:";
//     cin>>decimalNumber;

//     if(decimalNumber < 0){
//         cout<<"non negative number";
//         return 1;
//     }
//     cout<<"binaryNumber representation :";
//      decimalTobinary( decimalNumber);
//      return 0;
// }
// int main() {
//     int N;
//     cout << "Enter the number of integers: ";
//     cin >> N;

//     queue<int> myQueue;

//     cout << "Enqueue\n";
//     for (int i = 0; i < N; i++) {
//         int num;
//         cin >> num;
//         myQueue.push(num);

//         // Display the queue after each enqueue operation
//         queue<int> tempQueue = myQueue;
//         while (!tempQueue.empty()) {
//             cout << tempQueue.front() << " ";
//             tempQueue.pop();
//         }
//         cout << endl;
//     }

//     cout << "\nDequeue\n";
//     for (int i = 1; i < N; i--) {
//         myQueue.pop();

//         // Display the queue after each dequeue operation
//         queue<int> tempQueue = myQueue;
//         while (!tempQueue.empty()) {
//             cout << tempQueue.front() << " ";
//             tempQueue.pop();
//         }
//         cout << endl;
//     }

//     return 0;
// }

// typedef struct queue {
//   int front, rear;
//   int size, max;
//   int *arr;
// }Queue;

// Queue* createQueue(int max) {
//   Queue *queue = (Queue *)malloc(sizeof(Queue));
//   queue->max = max;
//   queue->front = 0;
//   queue->size = 0;
//   queue->rear = max - 1;
//   queue->arr = (int *)malloc(queue->max * sizeof(int));
//   return queue;
// }

// void reverseQueue(int arr[], int front, int rear){
//     while(front < rear){
//         int temp = arr[front];
//         arr[front] = arr[rear];
//         arr[rear] = temp;
//         front++;
//         rear--;
//     }
// }

// int main(){
//     int t;
//     cout<<"enter a number of queue";
//     cin>>t;

//     Queue *myQueue = createQueue(t);
//     cout << "Enter elements for the queue:" << endl;

//     for(int i = 0; i<t; i++){
//         int data;
//         cin >> data;
//         myQueue -> arr[i] = data;
//         myQueue -> size++;
//     }
//     cout << "Original Queue:" << endl;
//     for(int i = 0; i < myQueue->size; i++){
//         cout << myQueue->arr[i] << " ";
//     }

//     reverseQueue(myQueue->arr, 0, myQueue->size - 1);

//     cout << "\nReversed Queue:" << endl;
//     for(int i = 0; i < myQueue->size; i++){
//         cout << myQueue->arr[i] << " ";
//     }

//     free(myQueue->arr);
//     free(myQueue);

//     return 0;
// }

// int lastRemaningStone(int n) {
//     // Use a queue to simulate the process
//     queue<int>stones;
//     for (int i = 1; i <= n; ++i) {
//         stones.push(i);
//     }

//     while(stones.size() > 1) {
//         int currentStone = stones.front();
//         stones.pop();

//         int nextStone = stones.front();
//         stones.pop();

//         // Move the topmost stone to the bottom
//         stones.push(currentStone);
//     }

//     return stones.front();
// }

// int main() {
//     int T;
//     cin >> T;

//     for (int t = 0; t < T; t++) {
//         int N;
//         cin >> N;

//         // Output the result for each test case
//         int result = lastRemaningStone(N);
//         cout<<result<<endl;
//     }
//     return 0;
// }
