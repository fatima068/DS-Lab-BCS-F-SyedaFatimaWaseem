#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) :data(val),next(nullptr){} 
};

class Stack{
    private:
    Node* top;
    public:
    Stack() :top(nullptr) {}

    void push(int val){
        Node* newNode=new Node(val);
        newNode->next =top;
        top= newNode;
    }

    void pop(){
        if (isEmpty()) {
            cout << "Stack empty cannot pop" << endl;
            return;
        }
        Node* toDelete=top;
        int ans = toDelete->data;
        top= top->next;
        delete toDelete;
        cout<<"popped " << ans<< endl;
    }

    bool isEmpty() {
        if (top == nullptr) return true;
        return false;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main() {
    Stack browserHistory;
    cout << "browser history:" << endl;
    cout << "push 1: visit google" << endl;
    browserHistory.push(1);
    cout << "push 2: visit youtube" << endl;
    browserHistory.push(2);
    cout << "push 3: visit netflix" << endl;
    browserHistory.push(3);
    cout << "history: ";
    browserHistory.print();
    cout << endl << "when back button: ";
    browserHistory.pop();

    cout << "history: ";
    browserHistory.print();
    cout << "going back: ";
    browserHistory.pop();
    cout << "history: ";
    browserHistory.print();
    cout << "going back: ";
    browserHistory.pop();
    browserHistory.pop();
}
