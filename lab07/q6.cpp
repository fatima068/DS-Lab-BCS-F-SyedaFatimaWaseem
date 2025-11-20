#include <iostream>
using namespace std;

int findMax(int numbers[], int count){
    int biggest =numbers[0];
    for (int i = 1; i<count; i++) {
        if (numbers[i]> biggest) {
            biggest =numbers[i];
        }
    }
    return biggest;
}

void sortByDigit(int numbers[], int count,int digitPlace) {
    int temp[count];
    int digitCount[10] ={0};  // Count how many of each digit 
    
    for (int i = 0; i<count; i++) {
        int digit =(numbers[i] / digitPlace) % 10;
        digitCount[digit]++;
    }
    for (int i = 1; i< 10; i++){
        digitCount[i] += digitCount[i -1];
    }
    
    for (int i = count - 1; i>= 0; i--) {
        int digit = (numbers[i]/ digitPlace) % 10;
        temp[digitCount[digit]- 1] = numbers[i];
        digitCount[digit]--;
    }
    for (int i = 0; i < count; i++) //copy to org arr
        numbers[i] = temp[i];
}

void radixSort(int numbers[], int count) {
    int biggest = findMax(numbers, count);
    for (int digitPlace = 1; biggest / digitPlace > 0; digitPlace *= 10) {
        sortByDigit(numbers, count, digitPlace);
    }
}

void merge(int numbers[], int start, int middle, int end) {
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    int left[leftSize], right[rightSize];
    
    for (int i = 0; i < leftSize; i++) {
        left[i] = numbers[start + i];
    }
    for (int j = 0; j < rightSize; j++) {
        right[j] = numbers[middle + 1 + j];
    }
        int i = 0, j = 0, k = start;
    
    while (i < leftSize && j < rightSize){
        if (left[i] <= right[j]) {
            numbers[k] = left[i];
            i++;
        } 
        else{
            numbers[k]= right [j];
            j++;
        }
        k++;
    }
    
    while (i< leftSize) {
        numbers[k]= left [i];
        i++;
        k++;
    }
    
    while (j< rightSize) {
        numbers[k]= right [j];
        j++;
        k++;
    }
}

void mergeSort(int numbers[],int start, int end) {
    if (start <end){
        int middle =start+ (end- start) / 2;
        mergeSort(numbers, start,middle);
        mergeSort(numbers, middle+1, end);
        merge(numbers, start, middle, end);
    }
}

void combineArrays(int firstArray[], int secondArray[], int combinedArray[], int size) {
    for (int i = 0; i < size; i++) {
        combinedArray[i] = firstArray[i];
        combinedArray[i + size] = secondArray[i];
    }
}

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void print(int numbers[], int size) {
    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
}
int main() {
    int arr1[10] = {170, 45, 75, 90, 2, 802, 24, 66, 123, 1};
    int arr2[10] = {34, 567, 89, 12, 999, 43, 76, 234, 65, 8};
    int combinedList[20];  
    int workingCopy[20];
  
    cout << "arr 1 original: ";
    for (int i = 0; i < 10; i++) 
        cout << arr1[i] << " ";
    cout << endl;  
    cout << "arr 2 original: ";
    for (int i = 0; i < 10; i++) 
        cout << arr2[i] << " ";
    cout << endl;
  
    combineArrays(arr1, arr2, combinedList, 10)
    cout << "using radix: ";
    copyArray(combinedList, workingCopy, 20);
    radixSort(workingCopy, 20);
    print(workingCopy, 20 );
    cout << "usig merge sort: " ;
    copyArray(combinedList, workingCopy, 20);
    mergeSort(workingCopy, 0, 19);
    print(workingCopy, 20 );
}
