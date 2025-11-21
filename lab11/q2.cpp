/*Task # 2: Some ABC university students want to develop an ASCII code-based dictionary app for their Final Year Project. This app should allow the users to perform the following operations:
a) Add_Record () This function will take a string input from user and add into the dictionary. For adding the string user will use a unique hash function k MOD 100 (table size must be 100, for k user will calculate the SUM of ASCII character of that word).
b) Word_Search () User will only pass a single string. If string is not available then generate an error message.
c) Print_Dictionary () Users can also display the complete dictionary.*/
#include <iostream>
#include <string>
using namespace std;

struct TableEntry {
    string key;
    string value;
    TableEntry* next;
    TableEntry(string k, string v) : key(k), value(v), next(nullptr) {}
};

class HashDictionary {
private:
    TableEntry* table[100];
    int computeHash(string key) {
        int sum = 0;
        for (char c : key) {
            sum += (int)c;
        }
        return sum % 100;
    }
    public:
    HashDictionary() {
        for (int i = 0; i < 100; i++) {
            table[i] = nullptr;
        }
    }
    
    void insertEntry(string key, string value) {
        int index = computeHash(key);
        TableEntry* newEntry = new TableEntry(key, value);
        newEntry->next = table[index];
        table[index] = newEntry;
    }
    
    void searchKey(string key) {
        int index = computeHash(key);
        TableEntry* current = table[index];
        
        while (current != nullptr) {
            if (current->key == key) {
                cout << "search key " << key << ": " << current->value << endl;
                return;
            }
            current = current->next;
        }
        cout << "Key " << key << " not found!" << endl;
    }
    
    void deleteKey(string key) {
        int index = computeHash(key);
        TableEntry* current = table[index];
        TableEntry* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } 
                else {
                    prev->next = current->next;
                }
                delete current;
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Key " << key << " not found for deletion!" << endl;
    }
    
    void displayIndex(int index) {
        if (index < 0 || index >= 100) {
            cout << "Invalid index!" << endl;
            return;
        }
        cout << "index " << index << ": ";
        TableEntry* current = table[index];
        bool first = true;
        
        while (current != nullptr) {
            if (!first) {
                cout << " -> ";
            }
            cout << "(" << current->key << ", " << current->value << ")";
            first = false;
            current = current->next;
        }
        
        if (first) {
            cout << "empty";
        }
        cout << endl;
    }
    
    ~HashDictionary() {
        for (int i = 0; i < 100; i++) {
            TableEntry* current = table[i];
            while (current != nullptr) {
                TableEntry* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashDictionary dict;
    dict.insertEntry("AB", "FASTNU");
    dict.insertEntry("CD", "CS");
    dict.insertEntry("EF", "hi"); 
    dict.searchKey("AB");
    dict.deleteKey("EF");
    dict.displayIndex(31);  
    dict.displayIndex(35);  
}
