// Task #2:
// Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
// => Rows represent benches, columns represent seats on each bench.
// => Initialize the array with 0 (empty).
// => Let the user fill seats (1 for occupied).
// => Print the final seating chart in matrix form.

#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of benches (rows): ";
    cin >> rows;
    cout << "Enter number of seats per bench (columns): ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            arr[i][j] = 0;
    }

    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<cols; j++) {
            cout << "seat " << i << ", " << j << ": enter 0 for seat empty or 1 for seat filled: ";
            cin >> arr[i][j];
        }
    }

    cout << "SEATING CHART" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
