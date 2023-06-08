#include <iostream>
// https://www.geeksforgeeks.org/namespace-in-c/
using namespace std;
namespace ns{
	// A Class in a namespace
	class geek{
	 public:
		void display()
		{cout<<"ns::geek::display()"<<endl;;}
	};
}
int main(){
	// Creating Object of geek Class
	ns::geek obj;
	obj.display();
}
