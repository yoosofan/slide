#include <iostream>
// https://www.geeksforgeeks.org/namespace-in-c/
using namespace std;
// Creating a namespace
namespace ns {
  void display();
  class geek {
   public:
    void display();
  };
} // namespace ns

// Defining methods of namespace
void ns::geek::display()
{cout << "ns::geek::display()\n";}
void ns::display(){cout << "ns::display()\n";}
int main(){
	ns::geek obj;
	ns::display();
	obj.display();
}
