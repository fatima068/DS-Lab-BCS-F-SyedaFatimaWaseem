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

    void traversePostOrder(Node* root) { // left right root 
        if (root == nullptr) 
        {return;}
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        cout << root->data << "  ";
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
        else  root->right = insertVal(root->right, val);
        return root;
    }

    void insertVal(int val[], int n) {
        for (int i = 0; i < n; i++) 
            root = insertVal(root, val[i]);
    }

    Node* minNode(Node* root) {
        while (root->left != nullptr) 
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int val) { 
        if (root == nullptr) {
            cout << "not found" << endl;
            return root;
        }
        else if (val < root->data) {
            root->left = deleteNode(root->left, val);
        }
        else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        }
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                Node* temp = minNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);             
            }
        }
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
};

int main() {    
    Node* root=new Node(50);
    BinaryTree tree(root);
    int values[]={30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int numValues = sizeof(values)/sizeof(values[0]);
    tree.insertVal(values,numValues);
    
    cout<< "Pre order traversal: ";
    tree.traversePreOrder(tree.root);
    cout<< endl;
    cout<< "In order: ";
    tree.traverseInOrder(tree.root);
    cout<<endl;
    cout<<"Post order: ";
    tree.traversePostOrder(tree.root);
    cout<< endl;
    
    cout<<"search 40: "; tree.search(tree.root,40);
    cout<<"search 100: ";tree.search(tree.root, 100);
    
    cout << "delete 20: "<< endl;
    tree.root = tree.deleteNode(tree.root, 20);
    tree.traverseInOrder(tree.root);
    cout <<endl;
    cout << "Delete 50: "<< endl;
    tree.root = tree.deleteNode(tree.root, 50);
    tree.traverseInOrder(tree.root);
    cout <<endl;
    
}
