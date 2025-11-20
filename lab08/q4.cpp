#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* right;
    Node* left;
    Node(int data) : data(data), right(nullptr), left(nullptr) {}
};

class BinaryTree {
    public:
    Node* root;

    BinaryTree(Node* root) : root(root) {}
    void traversePreOrder(Node* root){ // root, left, right
        if (root == nullptr) { return; }
        cout << root->data << "  " ;
        traversePreOrder(root->left) ;
        traversePreOrder(root->right);
    }

    void traverseInOrder(Node* root){ // left, root, right
        if (root == nullptr) {return; }
        traverseInOrder(root->left);
        cout << root->data << "  ";
        traverseInOrder(root->right);
    }
Node* insertVal(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val); 
        }
        if (val == root->data) {
            cout << "insert only unique values" << endl;
            return root;
        }
        if (val < root->data) {
            root->left = insertVal(root->left, val); 
        }
        else  root->right =insertVal(root->right, val);
        return root;
    }

    void insertVal(int val[], int n) {
        for (int i = 0; i < n; i++) 
            root= insertVal(root, val[i]);
    }

    Node* minNode(Node* root) {
        while (root->left != nullptr) 
            root= root->left;
        return root;
    }
    bool search(Node* root, int val) {
        if (root == nullptr) {
            cout << "not found" << endl;
            return false;
        }
        if (val <root->data){
            return search(root->left,val);
        } else if(val > root->data){
            return search(root->right, val);
        }
        else {
            cout << "value found " << endl;
            return true;
        }
    }
    
    void searchAndInsert(int val) {
        if (!searchValue(root, val)) {
            cout << val << " not found in tree so inserting it into tree "<<endl;
            root = insertVal(root, val);
            cout << "tree after insertion:" << endl;
            traverseInOrder(this->root);
        } else {
            cout << val << " already exists in the tree" <<endl;
            cout << "Current tree:" <<endl;
           traverseInOrder(this->root);}
    }

    bool searchValue(Node* root, int val) {
        if (root == nullptr) {
            return false;
        }
        if (val < root->data){
            return searchValue(root->left, val);
        } else if(val > root->data){
            return searchValue(root->right, val);
        }
        else return true;
    }
};

int main() {    
    Node* root = new Node(50);
    BinaryTree tree(root);
    int values[] = {30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int numValues = sizeof(values) / sizeof(values[0]);
    tree.insertVal(values, numValues);
    int userValue;
    cout << "enter a value to search for: ";
    cin >> userValue;
    tree.searchAndInsert(userValue);
}
