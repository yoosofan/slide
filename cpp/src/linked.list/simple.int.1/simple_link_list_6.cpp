#include<iostream>
using namespace std;
class Node{ public: 
  int data;
  Node *next;
};

class list{
  Node *head=nullptr;
  public: 
  void dispAll(){
    Node* pn = head;
    if(!pn){
      cout<<"List is empty";
      cout<<endl;
    }
    while(pn){
      cout << pn->data;
      cout << endl;
      pn = pn->next;
    }
}
  void append(int d){
    Node *pn = head;
    for( ; pn && pn->next; )
      pn = pn->next;
    if(pn){
      pn->next = new Node;
      pn = pn->next;
    }
    else
      pn = head = new Node;
    pn->next = nullptr ;
    pn->data = d;
  }
};
int main(){
  list l1;
  l1.append(3);
  l1.append(4);  
  l1.dispAll();
}
