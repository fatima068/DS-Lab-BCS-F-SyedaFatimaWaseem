// Implement a C++ function sumTail(int n, int total) that calculates the sum
// of numbers from 1 to n using tail recursion. The recursive call should be the last
// operation in the function.

// 2. Implement another function sumNonTail(int n) that calculates the same sum
// using non-tail recursion. This function should perform an operation (e.g., addition) after
// the recursive call returns. Compare the two implementations and explain the difference
// in their call stacks.
#include <iostream>
using namespace std;
 int sumtail(int n, int total=0){
    if (n==0) return total;
    return sumtail(n-1, total+n);
 }

int sumNontail(int n) {
    if(n==0) return 0;
    int ans = sumNontail(n-1);
    ans = ans + n;
    return ans;
} 

int main(){
    cout<<"enter n to total: ";
    int n;
    cin >>n;
    cout<<"using tail: ";
    int ans =sumtail(n);
    cout<<ans;
    cout<< endl<<"using nontail: ";
    ans = sumNontail(n);
    cout <<ans;
}
