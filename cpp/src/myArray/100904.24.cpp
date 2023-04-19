#include <iostream>
using namespace std;
int main(){
    int x = 10;
  
    // ptr1 holds address of x
    int* ptr1 = &x;
  
    // Now ptr2 also holds address of x.
    // But note that pt2 is an alias of ptr1.
    // So if we change any of these two to
    // hold some other address, the other
    // pointer will also change.
    int*& ptr2 = ptr1;
  
    int y = 20;
    ptr2 = &y;
  
    // Below line prints 20, 20, 10, 20
    // Note that ptr1 also starts pointing
    // to y.
    cout << *ptr1 << " " << *ptr2 << " "
         << x << " " << y;
  
    return 0;
}
// 20 20 10 20
// https://www.geeksforgeeks.org/

// https://www.geeksforgeeks.org/reference-to-a-pointer-in-c-with-examples-and-applications/