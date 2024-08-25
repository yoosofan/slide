//	https://www.programiz.com/cpp-programming/return-reference
#include <iostream>
using namespace std;
// Global variable
int global_num=1;
// Function declaration
int& test();
int main(){
    test() = 5;
    cout << global_num << endl;
    return 0;
}
int& test(){
    return global_num;
}
/*
Ordinary function returns value but this function doesn't. Hence, you cannot return a constant from the function.

int& test() {
    return 2;
}
*/
/*
You cannot return a local variable from this function.

int& test(){
    int n = 2;
    return n;
}
*/
