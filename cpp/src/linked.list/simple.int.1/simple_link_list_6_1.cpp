#include<iostream>
using namespace std;
class Node{    public: 
  int data;
  Node *next;
};
class list{
    Node *head = nullptr;    public: 
    void dispAll(void){
      Node *pn = head;
      if(!pn){
        cout << "List is empty";
        cout << endl;
      }
      while(pn){
        cout << pn->data;
        cout << endl;
        pn = pn->next;
      }
    }
    void append(int d){
      Node *pn = head;
      Node *pv = nullptr;
      for(; pn ; pn = pn->next)
        pv = pn;
      if(head){
        pv->next = new Node;
        pv = pv->next;
      }
      else pv = head = new Node;
      pv->next = nullptr;
      pv->data = d;
    }
};
int main(){
    list l1;
    l1.append(3);
    l1.append(4);  
    l1.dispAll();
}
