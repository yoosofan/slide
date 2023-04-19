#include <iostream>
#include <cmath>
using namespace std;
struct nodeCls{
  double data;
  nodeCls* next = nullptr;
  nodeCls(double a)
  {data = a; next = nullptr;}
  nodeCls(double a, nodeCls* n)
  {data = a; next = n;}
  nodeCls() = default;
};
int main(){
  nodeCls a(1), b(2), c(3), d(4);
  nodeCls* p;
  a.next = &b; b.next = &c; 
  c.next = &d; 
  p = &a;
  cout << p -> data << endl;
  p = p -> next;
  cout << p -> data <<  endl;
  p = p -> next;
  cout << p -> data << endl;
  p = p -> next;
  cout << p -> data << endl;
}