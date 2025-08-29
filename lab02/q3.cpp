// Task #3:
// Design a program to handle marks of students in different courses using a jagged array
// (since each student is enrolled in a different number of courses).
// => Input the number of courses each student takes.
// => Dynamically allocate memory for each student accordingly.
// => Calculate and display each student’s average marks.

#include <iostream>
using namespace std;

int main() {
    int numOfStudents;
    cout << "enter number of students: ";
    cin >> numOfStudents;

    int *numOfCourses = new int[numOfStudents];
    for (int i = 0; i < numOfStudents; i++) {
        cout << "enter num of courses for student " << i+1 << ": ";
        cin >> numOfCourses[i];
    }

    int **arr = new int*[numOfStudents];
    for (int i = 0; i < numOfStudents; i++) {
        arr[i] = new int[numOfCourses[i]];
    }

    for (int i = 0; i <numOfStudents; i++) {
        for (int j = 0; j<numOfCourses[i]; j++) {
            cout << "enter marks for student " << i + 1 <<", course " << j +1 << ": ";
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < numOfStudents; i++) {
        float avg, total = 0;
        for (int j = 0; j < numOfCourses[i]; j++) {
            total += arr[i][j];
        }
        avg = total / numOfStudents;
        cout << "avg  mark for std  " << i + 1 << " is " << avg << endl;
    }

    cout << "MARKS ARRAY: " << endl;
    for (int i = 0; i<numOfStudents; i++) {
        for (int j = 0; j<numOfCourses[i]; j++) {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }

    for (int i = 0; i < numOfStudents; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] numOfCourses;
}