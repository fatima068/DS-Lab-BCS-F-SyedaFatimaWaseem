/*Task # 1: Suppose you are working on a program that needs to store a large number of strings, with the possibility of duplicate strings. You decide to use chain hashing to efficiently store and retrieve the strings, but you want to ensure that collisions are avoided as much as possible. Your hash function simply takes the sum of the ASCII values of the characters in the string and returns the remainder after dividing by the number of buckets. You decide to implement the hash table using a linked list for each bucket.*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
    Node* next;
    
    Node(string k, string v) : key(k), value(v), next(nullptr) {}
};

class LinkedList {
    private:
    Node* head;
    
    public:
    LinkedList() : head(nullptr) {}
    
    void insert(string k, string v) {
        Node* curr_node = head;
        while (curr_node != nullptr) {
            if (curr_node->key == k) {
                curr_node->value = v;
                return;
            }
            curr_node = curr_node->next;
        }
        
        Node* new_node = new Node(k, v);
        new_node->next = head;
        head = new_node;
    }
    
    string search(string k) {
        Node* curr_node = head;
        while (curr_node != nullptr) {
            if (curr_node->key == k) {
                return curr_node->value;
            }
            curr_node = curr_node->next;
        }
        return "";
    }
    
    void display() {
        Node* curr_node = head;
        while (curr_node != nullptr) {
            cout << "(" << curr_node->key << "=" << curr_node->value << ")";
            if (curr_node->next != nullptr) {
                cout << " => ";
            }
            curr_node = curr_node->next;
        }
    }
    
    ~LinkedList() {
        Node* curr_node = head;
        while (curr_node != nullptr) {
            Node* temp_node = curr_node;
            curr_node = curr_node->next;
            delete temp_node;
        }
    }
};

class HashTable {
    private:
    LinkedList* buckets;
    int totalBuckets;
    
    int calculateHash(string k) {
        int ascii_total = 0;
        for (int i = 0; i < k.length(); i++) {
            ascii_total += (int)k[i];
        }
        return ascii_total % totalBuckets;
    } 
    public:
    HashTable(int bucket_count = 10) {
        totalBuckets = bucket_count;
        buckets = new LinkedList[totalBuckets];
    }
    
    void insert(string k, string v) {
        int bucket_index = calculateHash(k);
        cout << "Adding " << k << " to bucket " << bucket_index << endl;
        buckets[bucket_index].insert(k, v);
    }
    
    string search(string k) {
        int bucket_index = calculateHash(k);
        return buckets[bucket_index].search(k);
    }
    
    void display() {
        for (int i = 0; i < totalBuckets; i++) {
            cout << "Bucket[" << i << "]: ";
            buckets[i].display();
            cout << endl;
        }
    }
    
    void showBucket(string k) {
        int bucket_index = calculateHash(k);
        cout << "Bucket[" << bucket_index << "] for '" << k << "': ";
        buckets[bucket_index].display();
        cout << endl;
    }
    
    ~HashTable() {
        delete[] buckets;
    }
};

int main() {
    HashTable myhash(5);
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");
    myhash.display();
    cout << "Find A: " << myhash.search("A") << endl;
    cout << "Find B: " << myhash.search("B") << endl;
    cout << "Find C: " << myhash.search("C") << endl;
    cout << "Find D: " << myhash.search("D") << endl;
    myhash.showBucket("A");
    myhash.showBucket("B");
    myhash.showBucket("C");
}
