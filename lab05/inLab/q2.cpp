// Write a simple C++ program that demonstrates direct recursion. Create a function
// printNumbers(int n) that prints numbers from n down to 1 by calling itself
// directly.

// 2. Next, demonstrate indirect recursion by creating two functions, functionA(int n)
// and functionB(int n). functionA should call functionB, and functionB
// should call functionA, forming a cycle that prints numbers in a specific pattern.
// Ensure both programs have a base condition to prevent infinite loops..
#include <iostream>
using namespace std;
void funcB(int n);

void printnumbers(int n){
    if(n==0) return;
    cout<<n<<", ";
    printnumbers(n-1);
}

void funcA(int n) {
    if(n==0) return;
    cout<<"  "<<n;
    funcB(n-5);
}

void funcB(int n){
    if(n==0) return;
    cout<<"  " <<n;
    funcA(n-5);
}
int main(){
    cout<<"enter n for print:";
    int n;
    cin>>n;
    cout<<"enter large val of n for indirect resursion(print pattern with difference of 5): ";
    int x;
    cin >> x;
    printnumbers(n);
    cout<<endl;
    funcA(x);
}
