#include <iostream>
using namespace std;

int main() {
    int size, index;
    cout << "enter size of array to create: ";
    cin >> size;

    int *arr = new int[size];
    for (int i = 0; i<size; i++) {
        arr[i] = 0;
    }

    while(1) {
        cout << "enter index to input new val, -1 to exit: ";
        cin >> index;
        if (index == -1) {
            cout << "exiting....";
            break;
        }
        if (index >= size) {
            cout << "invalid index" << endl;
            continue;
        }
        cout << "enter value for index " << index << ": ";
        cin >> arr[index];
    }
    
    for (int i = 0; i<size; i++) {
        cout << arr[i] << "  ";
    }

    delete[] arr;
}
