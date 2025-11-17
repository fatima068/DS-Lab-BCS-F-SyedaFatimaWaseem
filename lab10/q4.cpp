/*Task#4: Given an array representation of min Heap, convert it to max Heap.
Examples:
Input: arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9}
         3
      /     \
     5       9
    / \     / \
  6   8 20 10
 / \ /
12 18 9
Output: arr[] = {20, 18, 10, 12, 9, 9, 3, 5, 6, 8}*/

#include <iostream>
using namespace std;

int getLargestIndex(int temp[], int n) {
    int index=0;
    for (int i=1; i<n;i++) {
        if (temp[i] >temp[index]){
            index =i;
        }
    }
    return index;
}
int main() {
    int n=10;
    int arr[10] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};

    int temp[10];
    for (int i=0; i<n;i++) {
        temp[i]= arr[i];
    }
    
    int remaining =n;
    for (int i= 0;i< n;i++) {
        int index = getLargestIndex(temp, remaining);
        arr[i] = temp[index];              
        temp[index] = temp[remaining - 1];   
        remaining--;
    }

    for (int i=0; i< n;i++) {
        cout << arr[i]<<" ";
    }
    cout << endl;
}
