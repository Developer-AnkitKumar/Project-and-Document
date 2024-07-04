#include<iostream>
using namespace std;

//int index;
int parent(int i){
    return ((i-1)/2);
}

int left(int i){
    return (2*i)+1;
}

int right(int i){
    return  (2*i)+2;
}

void insert(int heap[], int i, int val){
    heap[i] =val;
    while(i != 0 && heap[parent(i)] > heap[i]){
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void heapify(int heap[], int n, int i){
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
        heapify(heap, n, s);
    }
}


void remove(int heap[], int& n, int i){
    heap[i] = heap[n-1];
    n--;
    heapify(heap, n, i);
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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int heap[n];
        int ele;
        for(int i = 0; i<n; i++){
            cin>>ele;
            insert(heap, i, ele);
            remove(heap, n, 2);
             }
        print_heap(heap, n);
    }
    return 0;
}