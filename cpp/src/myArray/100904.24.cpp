#include <iostream>
using namespace std;
int main(){
    int x = 10;
  
    int* ptr1 = &x;
  
    int*& ptr2 = ptr1;
    // int ptr3 = ptr1 // Error
    // int& ptr4 = ptr1;
    
    // int ptr5;
    // ptr5 = ptr1 // Error
    // ptr5 = *ptr1; // ptr2 = x;
    
    // int * ptr6;
    // ptr6 = ptr1; 
    
    int y = 20;
    ptr2 = &y;
  
    cout << *ptr1 << " " << *ptr2 << " "
         << x << " " << y << endl;;
}
// 20 20 10 20
// https://www.geeksforgeeks.org/
