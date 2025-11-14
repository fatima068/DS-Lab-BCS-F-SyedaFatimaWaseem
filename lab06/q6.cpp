#include <iostream>
#include <string>

#include<cmath>
using namespace std;
class Stack { // use simple array stack
    private:
    string* arr;
    int top;
    int size;
public:
    Stack(int n){
        size = n;
        arr=new string[size];
        top =-1;
    }
    void push(string x){
        if (top == size - 1) return;
        arr[++top] = x;
    }

    string pop() {
        if (top== -1) return "";
        return arr[top--];
    }

    string peek(){
        if (top ==-1) return "";
        return arr[top];
    }

    bool empty() {
        return top== -1;
    }
    ~Stack() {
        delete[] arr;
    }
};

class NumStack{
private:
    float* arr;
    int top;
    int size;

public:
    NumStack(int n) {
        size= n;
        arr=new float[size];
        top =-1;
    }
    void push(float x){
        if (top == size- 1) return;
        arr[++top]= x;
    }

    float pop(){
        if (top== -1) return -1;
        return arr[top--];
    }

    bool empty() {
        return top == -1;
    }
    ~NumStack() {
        delete[] arr;
    }
};

class Converter {
  private:
    int getPrec(string op){
        if (op == "^") return 3;
        if (op == "*"|| op == "/") return 2;
        if (op == "+"||op == "-") return 1;
        return 0;
    }

    public:
    string toPostfix(string infix){
        Stack ops(50);
        string postfix = "";
        string token = "";
        
        for(int i = 0; i < infix.length(); i++) {
            char c =infix[i];
            
            if (c == ' '){continue;  }
            if (isdigit(c)|| c=='.') {
                token += c;
            } else{
                if (!token.empty()) {
                    postfix += token + " ";
                    token = "";
                }
                if (c =='(') {
                    ops.push("(");
                } else if(c == ')') {
                    while(!ops.empty() && ops.peek() != "("){
                        postfix +=ops.pop() + " ";
                    }
                    ops.pop();
                } else{
                    string op(1, c);
                    while (!ops.empty() && getPrec(ops.peek()) >= getPrec(op)) {
                        postfix += ops.pop() + " ";
                    }
                    ops.push(op);
                }
            }
        }
        if (!token.empty()){
            postfix +=token + " ";
        }
        while (!ops.empty()){
            postfix += ops.pop() + " ";
        }
        return postfix;
    }

    string toPrefix(string infix) {
        Stack ops(50);
        string prefix = "";
        string token = "";
        
        // Reverse the infix expression
        string reversed = "";
        for(int i = infix.length()-1; i >=0; i--) {
            char c = infix[i];
            if(c == '(') reversed += ')';
            else if(c == ')') reversed += '(';
            else reversed += c;
        }
        
        // Process reversed infix to get reversed postfix
        for(int i = 0; i < reversed.length(); i++) {
            char c =reversed[i];
            
            if (c == ' '){continue;  }
            if (isdigit(c)|| c=='.') {
                token += c;
            } else {
                if (!token.empty()) {
                    prefix = token + " " + prefix;
                    token = "";
                }
                if (c == '(') {
                    ops.push("(");
                } else if (c == ')') {
                    while(!ops.empty() && ops.peek() != "("){
                        prefix = ops.pop() + " " + prefix;
                    }
                    ops.pop();
                } else {
                    string op(1, c);
                    while (!ops.empty() && getPrec(ops.peek()) > getPrec(op)) {
                        prefix = ops.pop() + " " + prefix;
                    }
                    ops.push(op);
                }
            }
        }
        if (!token.empty()) {
            prefix = token + " " + prefix;
        }
        while(!ops.empty()) {
            prefix =ops.pop() +" "+ prefix;
        }
        return prefix;
    }

    float calculatePostfix(string postfix) {
        NumStack nums(50);
        string token ="";
        for (int i = 0; i<postfix.length(); i++) {
            char c=postfix[i];
            if (c == ' ') {
                if (!token.empty()) {
                    if (isdigit(token[0])) {
                        nums.push(stof(token));
                    } else {
                        float b = nums.pop();
                        float a = nums.pop();
                        if (token=="+") nums.push(a + b);
                        else if (token=="-") nums.push(a-b);
                        else if (token=="*") nums.push(a * b);
                        else if (token =="/") nums.push(a / b);
                        else if (token =="^") nums.push(pow(a,b));
                    }
                    token ="";
                }
            }else{
                token+= c;
            }
        }
        return nums.pop();
    }

    float calculatePrefix(string prefix) {
        NumStack nums(50);
        string token ="";
        for (int i = prefix.length()-1; i>=0; i--) {
            char c=prefix[i];
            if (c ==' ') {
                if (!token.empty()) {
                    if(isdigit(token[0])) {nums.push(stof(token)); } else {
                        float a = nums.pop();
                        float b = nums.pop();
                        
                        if (token=="+") nums.push(a + b);
                        else if (token=="-") nums.push(a - b);
                        else if (token=="*") nums.push(a * b);
                        else if (token =="/") nums.push(a / b);
                        else if (token =="^") nums.push(pow(a,b));
                    }
                    token ="";
                }
            }else{ token = c + token; }
        }
        // forr last token
        if (!token.empty()) {
            if (isdigit(token[0])) {
                nums.push(stof(token));
            }
        }
        return nums.pop();
    }
};

int main(){
    Converter conv;
    string exp;
    
    cout<<"Enter expression: ";
    getline(cin,exp);
    string postfix = conv.toPostfix(exp);
    string prefix = conv.toPrefix(exp);
    cout <<"Prefix: "<< prefix << endl;
    float result = conv.calculatePrefix(prefix);
    cout << "Prefix Result: "<< result << endl;
}
