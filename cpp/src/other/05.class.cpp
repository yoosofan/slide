//	https://msdn.microsoft.com/en-us/library/z0c3dx2s.aspx
// refType_function_returns.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;
class Point{
public:
	// Define "accessor" functions as
	//  reference types.
	unsigned& x();
	unsigned& y();
private:
	// Note that these are declared at class scope:
	unsigned obj_x;
	unsigned obj_y;
};
unsigned& Point :: x(){return obj_x;}
unsigned& Point :: y(){return obj_y;}
int main(){
	Point ThePoint;
	// Use x() and y() as l-values.
	ThePoint.x() = 7;
	ThePoint.y() = 9;
	// Use x() and y() as r-values.
	cout << "x = " << ThePoint.x() << "\n"
		 << "y = " << ThePoint.y() << "\n";
}

