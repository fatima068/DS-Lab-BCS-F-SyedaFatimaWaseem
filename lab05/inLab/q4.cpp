// Write a C++ program that implements the Ackermann function, which is a classic example of
// nested recursion. The function ackermann(int m, int n) is defined as:
// ● If m=0, return n+1.
// ● If m>0 and n=0, return ackermann(m-1, 1).
// ● If m>0 and n>0, return ackermann(m-1, ackermann(m, n-1)).
// This task requires you to trace the execution and understand how one recursive call is a
// parameter to another.
#include <iostream>
using namespace std;
int ackerman(int m, int n){
    if(m==0)
        return n+1;
    if(m>0 && n==0){
        return ackerman(m-1,1);
    }
    if(m>0 && n>0){
        return ackerman(m-1, ackerman(m,n-1));
    }
    return 1;
}

int main() {
    cout<<"enter m: ";
    int m; cin >> m;
    cout<<"enter n: ";
    int n; cin >>n;
    int ans = ackerman(m,n);
    cout<<"ams: " << ans;
}
