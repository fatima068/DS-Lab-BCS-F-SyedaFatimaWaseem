#include <iostream>
using namespace std;

class Queue{
private:
    int *arr;
    int front;
    int back; 
    int  size;
    
public:
    Queue(int size):size(size), front(-1),back(-1){
        arr= new int[size];
    }
    
    void enqueue(int value){
        if (isFull()){
            cout<<"queue full"<< endl;
            return;
        }
        if(isEmpty()){
            front=0;
        }
        back++;
        arr[back] =value;
        cout << "Enqueued: "<< value << endl;
    }
    
    void dequeue() {
        if (isEmpty()){
            cout << "queue empty"<< endl;
            return;
        }
        cout<< "dequeued: " <<arr[front] << endl;
        if (front==back){
            front=-1;
            back=-1;
        }else {
            front++;
        }
    }
    
    void display(){
        if (!isEmpty()){
            for (int i=front; i<=back; i++) {
                cout<<arr[i] << " ";
            }
            cout<<endl;
        }
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return back== size -1;
    }
    
    ~Queue(){
        delete[] arr;
    }
};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();    
    q.dequeue();
    q.dequeue();
    cout << endl <<"after dequeuing twice:"<<endl;
    q.display();
    q.enqueue(60);
    q.enqueue(70);
    q.display();
}
