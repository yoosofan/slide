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
  nodeCls head;
  nodeCls* p = nullptr;
  head.next = new nodeCls(1);
  cout << head.next << endl;
  p = head.next;
  p -> next = new nodeCls(2);
  p = p -> next;
  p -> next = new nodeCls(3);
  p = p -> next;
  p -> next = new nodeCls(4);
  for(p = head.next; p; p = p -> next)
    cout << p -> data << endl;
}