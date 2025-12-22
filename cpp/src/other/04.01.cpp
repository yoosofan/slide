// Ahmad Yoosofan 2021/04/12 16:09:43 444444444
//	https://www.tutorialspoint.com/cplusplus/returning_values_by_reference.htm
#include <iostream>
#include <ctime>

using namespace std;

double& setValues( int i ) {
  static double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
  cout << "before change" << endl;
  for ( int i = 0; i < 5; i++ ) {
    cout << "vals[" << i << "] = ";
    cout << vals[i] << endl;
  }
  cout << "after change" << endl;
  return vals[i];   // return a reference to the ith element
}

// main function to call above defined function.
int main () {
  setValues(1) = 20.23; // change 2nd element
  setValues(3) = 70.8;  // change 4th element
}
