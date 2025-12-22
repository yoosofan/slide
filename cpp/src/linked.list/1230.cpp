#include <iostream>
using namespace std;
class listCls;
class nodeCls{
  double data;
  nodeCls* next = nullptr;
  public:
  nodeCls(double a)
  {data = a; next = nullptr;}
  nodeCls() = default;
  friend class listCls;
  bool operator==(const nodeCls& b)
  {return data == b.data;}
  bool operator<=(const nodeCls& b)
  {return data <= b.data;}
  bool operator>=(const nodeCls& b)
  {return data >= b.data;}
  bool operator!=(const nodeCls& b)
  {return data != b.data;}
  bool operator<(const nodeCls& b)
  {return data < b.data;}
  bool operator>(const nodeCls& b)
  {return data > b.data;}
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
  double& operator[](int index){
    nodeCls* p = head.next;
    for(int i = 0; i < index && p; i++)
      p = p -> next;
    if(p) return p -> data;
    cout << "index is out of range" << endl;
    return head.data;
  }
  bool remove(int index = 0){
    nodeCls* p = &head; 
    bool retVal = false;
    for(int i = 0; i < index && p -> next; i++)
      p = p -> next;
    if(p -> next){
      nodeCls* t1 = p -> next;
      p -> next = p -> next -> next;
      delete t1;
      retVal = true;
    }
    else
      cout << "index is out of range" << endl;
    return retVal;
  }
};
int main(){
  listCls l1; l1.append(1); l1.append(2); 
  l1.append(3); l1.append(4); 
  l1.print(); cout << l1[1] << endl;
  l1.remove(1); l1.print();
}