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

void print_heap(int heap[], int n){
    //for(int i = 0; i < n; i++){
        for(int i = n-1; i>=0; i--){
        cout << heap[i] << " ";
    }
    cout << "\n";
}

void heap_sort(int heap[], int n){
    build_heap(heap, n);
    for(int i = n-1; i>=0; i--){
        swap(heap[0], heap[i]);//change heap[i] = output[1 2 2 3 4 5 6 7 8 9 10 increasing order];
        heapify_down(heap, i, 0);//heap[1] = output[10 9 5 6 8 7 3 4 2 2 1];
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        size = 0;
        int n;
        cin>>n;
        int heap[n];
        for(int i = 0; i<n; i++){
            cin>>heap[i];
            size++;
        }
       // build_heap(heap, n);
        heap_sort(heap, n);
        print_heap(heap, n);
    }
    return 0;
}