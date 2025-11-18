#include <iostream>
#include <string>
using namespace std;

struct Node{
    string name;
    int score;
    Node* next;
    Node(string n,int s) :name(n), score(s),next(nullptr){}
};
void addNode(Node*& head, string name, int score){
    Node* n = new Node(name,score);
    if (!head) {
        head =n;
        return;
    }
    Node* t=head;
    while (t->next) t = t->next;
    t->next= n;
}

int getCount(Node* head) {
    int c= 0;
    while(head) {
        c+=1;
        head =head->next;
    }
    return c;
}

Node* getNodeAt(Node* head, int i) {
    while (i-- && head)
        head = head->next;
    return head;
}

int getMaxScore(Node* head){
    int max=-1;
    while (head !=nullptr){
        if (head->score > max) max = head->score;
        head =head->next;
    }
    return max;
}
Node* countingSort(Node* head, int exp){ 
    Node* bucket[10] ={nullptr};
    Node* tail[10] = {nullptr};

    Node* cur= head;

    while (cur) {
        int digit= (cur->score / exp) % 10;

        if (!bucket[digit]) {
            bucket[digit] = cur;
            tail[digit] = cur;
        } else {
            tail[digit]->next = cur;
            tail[digit] = cur;
        }
        cur= cur->next;
    }

    Node* newHead =nullptr;
    Node* newTail =nullptr;

    for (int i=0; i<10;i++) {
        if (bucket[i]) {
            if (!newHead){
                newHead = bucket[i];
                newTail = tail[i];
            } else {
                newTail->next = bucket[i];
                newTail = tail[i];
            }
        }
    }

    if (newTail) newTail->next = nullptr;
    return newHead;
}
void radixSort(Node*& head) {
    int mx = getMaxScore(head);
    for (int exp = 1; mx / exp > 0; exp *= 10)
        head = countingSort(head, exp);
}
void display(Node* head) {
    while (head) {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int binarySearch(Node* head, string name, int score) {
    int left= 0;
    int right =getCount(head)-1;

    while (left <=right) {
        int mid =(left+right)/ 2;
        Node* midNode = getNodeAt(head, mid);

        if (midNode->score ==score && midNode->name ==name)
            return mid;
        else if (midNode->score< score)
            left =mid+ 1;
        else
            right = mid- 1;
    }
    return -1;
}

void deleteNode(Node*& head, string name, int score) {
    if (!head) return;

    if (head->name == name && head->score == score) {
        Node* t =head;
        head =head->next;
        delete t;
        return;
    }

    Node* cur =head;
    while (cur->next) {
        if (cur->next->name== name && cur->next->score == score) {
            Node* t =cur->next;
            cur->next = cur->next->next;
            delete t;
            return;
        }
        cur = cur->next;
    }
}

int main() {
    Node* head = nullptr;

    addNode(head, "Ayan", 90);
    addNode(head, "Zameer", 60);
    addNode(head, "Sara", 70);
    addNode(head, "Sohail", 30);
    addNode(head, "Ahmed", 20);

    cout << "Before Sorting: ";
    display(head);
    radixSort(head);

    cout << "After Sorting: ";
    display(head);
    cout<<endl;
    string name;
    int score;
    cout << "enter student name to delete: ";
    cin >> name;
    cout << "Enter score: ";
    cin >> score;
    int pos = binarySearch(head, name, score);

    if (pos != -1) {
        deleteNode(head, name, score);
        cout << "updated list:\n";
        display(head);
    } else {
        cout << "not found \n";
    }

