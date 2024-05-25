#include<iostream>
using namespace std;
class Node{public:
  int data;
  Node *next;
};
class list{
  Node *head = nullptr;
  public:
  void dispAll(void){
    Node* pn = head;
    if(!head)
      cout<<"list is empty\n";
    for( ; pn ; pn = pn->next)
      cout << pn->data <<endl;
  }
  void ins_first(int d){
      Node *pn = head;
      head = new Node;
      head->next = pn;
      head->data = d;
  }
};
int main(){
    list l1;
    l1.ins_first(3);
    l1.ins_first(5);
    l1.dispAll();
}
