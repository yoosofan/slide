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
  a.next = &b; b.next = &c; 
  c.next = &d;
  cout << a.data << endl;
  cout << b.data << endl;
  cout << (*(a.next)).data << endl;
  cout << (a.next) -> data << endl;
  cout << (b.next) -> data << endl;
  cout << (a.next) -> next -> data << endl;
  cout << (b.next) -> next -> data << endl;
  cout << (a.next) -> next -> next -> data << endl;
  cout << d.data << endl;
}