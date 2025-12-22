#include<iostream>
using namespace std;
class Node{
  public:
   int data;
   Node *next=nullptr;
   Node(int data=0)
   {this->data = data;}
};
class list{
   Node head=nullptr;
  public:
   bool insert(int index , int data){
      Node * pn = & head;
      int i; bool retVal = true;
      for(i=0 ; i< index && pn->next; i++, pn = pn-> next)
           ;
      if(i==index){
         Node *pt = pn->next;
         pn->next= new Node();
         pn = pn -> next;
         pn -> data = data;
         pn -> next = pt;
      }
      else retVal = false;
      return retVal;
   }
   void displayAll(){
      for(Node *pn= head.next ; pn ; pn = pn -> next)
         cout<<pn->data<<endl;
   }
   int search(int data){
      int i;
      Node *pn = head.next;
      for(i=0; pn ; pn = pn->next, i++)
         if(pn->data == data)
            return i;
      return -1;
   }
   bool remove(int index){
      int i ;
      Node *pn = &head;
      bool retVal = true;
      for(i=0 ; i<index && pn->next ; i++, pn = pn-> next);
      if(pn->next){
         Node *pt = pn->next;
         pn->next = pn->next->next;
         delete pt;
      }
      else retVal= false;
      return retVal ;
   }
};
int main(){
   list l1;
   if(!l1.insert(0,9))
      cout<<" Index in out of range"<<endl;
   l1.insert(1,8);
   l1.insert(2,7);
   if(!l1.insert(5,6))
      cout<<" Index in out of range"<<endl;
   l1.displayAll();
   cout<<l1.search(8)<<endl;
   l1.remove(0);
   l1.displayAll();
   Node p1(2);
   Node ** n1;
   n1 = new Node * [3];
   n1[0] = new Node(3);
   n1[1] = new Node(6);
   n1[2] = nullptr;
   cout<<endl<<endl;
   for(int j=0; j<2; j++)
      cout<<n1[j]->data<<endl;
   return 0;
}
















