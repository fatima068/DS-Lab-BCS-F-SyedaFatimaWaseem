#include <iostream>
using namespace std;

class CircularQueue {
    private:
    int *arr;
    int cap;
    int size;
    int f;
    int r;
    
    public:
    CircularQueue(int n){
        cap= n;
        arr=new int[cap];
        f =0;
        r =-1;
        size=0;
    }

    void push(int x) {
        if (size == cap) {
            cout << "Queue is full! Can't add " << x << endl;
            return;
        }
        
        r = (r +1) % cap;
        arr[r] = x;
        size++;
    }

    void pop(){
        if (size == 0) {
            cout << "Queue is empty! Can't remove" << endl;
            return;
        }
        
        f = (f+ 1) % cap;
        size--;
    }

    bool empty() {
        return size == 0;
    }

    bool full() {
        return size == cap;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout<<"Queue: ";
        int count = 0;
        int i = f;
        
        while (count < size) {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
            count++;
        }
        cout << endl;
    }

    int front() {
        if (size == 0) {
            cout << "No front!" << endl;
            return -999;
        }
        return arr[f];
    }

    ~CircularQueue(){
        delete[] arr;
    }
};

int main() {
    CircularQueue q(4);    
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    cout << "Front is: " << q.front() << endl;
    q.push(40);
    q.display();
    
    q.push(50); // should  fail 
    
    q.pop();
    q.pop();
    q.display();
    q.push(100);
    q.push(200);
    q.display();
    
    cout << "Front now: " << q.front() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop(); // Should fail
}
