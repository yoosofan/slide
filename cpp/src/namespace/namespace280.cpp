#include <iostream>
// https://www.geeksforgeeks.org/namespace-in-c/
// Here we can see that more than one variables
// are being used without reporting any error.
// That is because they are declared in the
// different namespaces and scopes.
#include <iostream>
using namespace std;

// Variable created inside namespace
namespace first {int val = 500;}

// Global variable
int Global_Variable_Val = 100;

int main(){
	// Local variable
  int Global_Variable_Val = 100;
	// These variables can be accessed from
	// outside the namespace using the scope
	// operator ::
	cout << first::val << endl;
  cout << Global_Variable_Val << endl;
  cout << ::Global_Variable_Val << endl;
}
