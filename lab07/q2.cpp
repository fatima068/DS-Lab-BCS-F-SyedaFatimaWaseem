#include<iostream>
using namespace std;

int getMax(int arr[],int size){
        int max = arr[0];
        for(int i = 1;i<size;i++){
                if(arr[i] > max){
                        max = arr[i];
                }
        }
        return max;
}

void CountingSort(int arr[],int size,int div) {
        int output[size];
        int count[10] = {0};
        for(int i = 0;i<size;i++ )
        {
                count[(arr[i]/div)%10]++;
        }
        for(int i=1;i<size;i++){
                count[i] += count[i - 1];
        }
        for(int i = size-1;i>=0;i--){
                output[count[(arr[i]/div) % 10]-1] = arr[i];
                count[(arr[i]/div)%10]--;
        }
        for(int i = 0;i<size;i++){
                arr[i] = output[i];
        }
}

void RadixSort(int arr[], int size){
        int m = getMax(arr,size);
        for(int div = 1 ;m/div > 0;div *= 10){
                CountingSort(arr,size,div);
        }
}
int main(){
        int arr[] = {2,4,3,1,6,7,16,32};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted Array:"<<endl;
    for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    cout<<"Sorted Array Ascending: "<<endl;
    RadixSort(arr, size);
    for(int i=0;i<size;i++){
            cout<< arr[i] <<" ";
        }
        cout <<endl;
        cout<<"Sorted Array Descending:"<< endl;
    RadixSort(arr, size);
    for(int i=size-1;i >= 0;i--)
            cout<<arr[i]<<" ";
        cout<<endl;

}
