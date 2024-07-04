#include<iostream>
using namespace std;

int size;
int parent(int i){
    return ((i-1)/2);
}

int left(int i){
    return (2*i)+1;
}

int right(int i){
    return  (2*i)+2;
}

void heapify_down(int heap[], int n, int i){
    int l = left(i);
    int r = right(i);
    int s = i;
   
        if (l < n && heap[l] < heap[i]) {
            s = l;
        }
        if (r < n && heap[r] < heap[s]) {
            s = r;
        }
       
    if(s != i){
        swap(heap[i], heap[s]);
        heapify_down(heap, n, s);
    }
}

void build_heap(int heap[], int n){
    for(int i = (n/2-1); i >= 0; i--){
        heapify_down(heap, n, i);
    }
}

void create_min_heap(int heap[]){
    int root = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapify_down(heap, size, 0);
    return;
}

void decreaseKey(int heap[], int i, int val){
    heap[i] = val;
    while(i != 0 && heap[parent(i)] > heap[i]){
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void removeElement(int heap[], int i, int k){
    decreaseKey(heap, i, k);
    swap(heap[0], heap[size - 1]);
    size--;
    heapify_down(heap, size, 0);
}

void print_heap(int heap[], int n){
    for(int i = 0; i < n; i++){
        cout << heap[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cout<<"number of test case:";
    cin>>t;
    while(t--){
        size = 0;
        int n;
        cout<<"enter a number of integer value: ";
        cin>>n;
        int heap[n];
        for(int i = 0; i<n; i++){
            cin>>heap[i];
        //     size++;
         }
        int k;
        cout<<"remove the index position:";
        cin >> k;

        removeElement(heap, 2, k);

        for(int i = 0; i < size; i++) {
        cout << heap[i] << " ";
          }
           build_heap(heap, n);
        print_heap(heap, n);
    }
    return 0;
}