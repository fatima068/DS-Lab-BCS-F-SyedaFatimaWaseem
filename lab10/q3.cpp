/*Task#3: Given an integer array arr[] of size n elements and a positive integer K, thetask is to return the kth largest element in the given array (not the Kth distinctelement).
Examples:
Input: [1, 23, 12, 9, 30, 2, 50], K = 3, Output: 23
Input: [12, 3, 5, 7, 19], K = 2, Output: 12*/
#include <iostream>
using namespace std; 
class MaxHeap{ //delete once from heap, 1st largest element, delete twice from heap gives second largest elemenet
    public:
    int arr[100];
    int size;
    MaxHeap():size(0) {}

    void insert(int val){
        if(size ==100) {
            cout <<"heap overflow"<< endl;
            return;
        }
        arr[size] = val;
        heapifyUp(size);
        size++;
    }

    void heapifyUp(int index){
        while(index !=0&& arr[index] > arr[parent(index)]) {
            int temp = arr[index];
            arr[index] = arr[parent(index)];
            arr[parent(index)] = temp;

            index = parent(index);
        }
    }
    void display() {
        for(int i =0; i<size; i++) {
            cout << arr[i] << "  ";
        }
        cout <<endl;
    }

    int deleteRoot() {
        if(size ==0) {
            cout <<"heap underflow" <<endl;
            return -1;
        }
        int ret=arr[0];
        arr[0] =arr[size-1];
        size--;
        heapifyDown(0);
        return ret;
    }

    void heapifyDown(int index) {
        int largest =index;
        int l=leftChild(index);
        int r= rightChild(index);

        if(l< size &&arr[l]>arr[largest]) largest =l;
        if(r< size &&arr[r]>arr[largest])  largest =r;
        if(largest!= index) {
            int temp = arr[index];
            arr[index] = arr[largest];
            arr[largest]= temp;
            heapifyDown(largest);
        }
    }
    int parent(int i) {return (i-1) / 2; }
    int leftChild(int i){ return (2*i)+ 1; }
    int rightChild(int i){ return (2 * i) + 2;} 
};

int main (){
    MaxHeap heap;
    heap.insert(1);
    heap.insert(23);
    heap.insert(12);
    heap.insert(9);
    heap.insert(30);
    heap.insert(2);
    heap.insert(50);
    cout<<"heap: "; heap.display();
    cout<<"enter k: "; int k; cin>>k;
    int kthVal;
    for(int i=0;i<k; i++){
        kthVal = heap.deleteRoot();
    }
    if(kthVal != -1){
        cout << k<<"th largest is "<<kthVal<<endl;
    } else cout <<"values dont exist";
}
