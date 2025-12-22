#include <iostream>
using namespace std;
struct nodeCls{
  double data;
  nodeCls* next = nullptr;
  nodeCls(double a)
  {data = a; next = nullptr;}
  nodeCls() = default;
};
class listCls{
  nodeCls head;
  public:
  void append(double d){
    nodeCls* p = &head;
    for(; p -> next; p = p -> next)
    ;
    p -> next = new nodeCls(d);
  }
  void print(){
    nodeCls* p = head.next;
    for(; p; p = p -> next)
      cout << p -> data << '\t';
    cout << endl;
  }
};
int main(){
  listCls l1; l1.append(1);
  l1.append(2); l1.append(3);
  l1.append(4); l1.print();
}