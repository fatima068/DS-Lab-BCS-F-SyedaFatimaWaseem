#include <iostream>
using namespace std; 


void display(int arr[], int size) {
    for(int i =0; i<size; i++) {
        cout << arr[i] << "  ";
    }
    cout <<endl;
}

int parent(int i) {return (i-1) / 2; }
int leftChild(int i){ return (2*i)+ 1; }
int rightChild(int i){ return (2 * i) + 2; } 

bool isMaxHeap(int arr[], int size) {
    for (int i = (size/2)-1; i >= 0; i--) {
        int left = leftChild(i);
        int right = rightChild(i);
        //if left child greater than parent, not a max heap
        if (left < size && arr[left] > arr[i]) return false;   
        //if right child greater than parent, not a max heap  
        if (right < size && arr[right] > arr[i]) return false;
    }
}  

void heapSort(int arr[], int size){
    for (int i =(size/2)-1; i>=0;i--) {
        int largest = i;
        int left=leftChild(i);
        int right =rightChild(i);
        
        if (left< size && arr[left] >arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;
            
        if (largest!= i) {
            swap(arr[i], arr[largest]);
            i = largest + 1; 
        }
    }
    
    for (int i=size-1; i> 0; i--) {
        swap(arr[0], arr[i]); 
        int root= 0;
        while (true){
            int largest= root;
            int left = leftChild(root);
            int right= rightChild(root);
            
            if (left< i &&arr[left]> arr[largest])
                largest = left;
            if (right<i &&arr[right] >arr[largest])
                largest= right;               
            if (largest==root) break;
            swap(arr[root],arr[largest]);
            root = largest;
        }
    }
}

int main() {
    int heap1[] = {8, 7, 6, 5, 4};
    int heap2[] = {5, 8, 6, 3, 4};
    
    cout<<"arr1: "; display(heap1, 5);
    if (isMaxHeap(heap1, 5)) {
        cout << "Array 1 is max heap" << endl;
    } else {
        cout << "Array 1 is not max heap" << endl;
    }
    
    cout<<"arr2: "; display(heap2, 5);
    if (isMaxHeap(heap2, 5)) {
        cout<< "Array 3 is max heap" <<endl;
    } else {
        cout<< "Array 3 is not max heap" << endl;
    }

    heapSort(heap1, 5);
    cout<<"sorted heap1: "; display(heap1, 5);
}
