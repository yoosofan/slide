#include<iostream>
using namespace std;
struct Node{
  double data;
  Node *link;
  Node(double d=0,Node*link= nullptr)
  {this->data=d;this->link=link;}
  ~Node(){delete link;}
};
void print(Node*h){
  if(h)
  {cout<<h->data<<endl;print(h->link);}
}
void append(Node*h,double d=0){
  for(;h->link;h=h->link);
  h->link=new Node(d);
}
void i_here(Node*cur,double d=0){
    cur -> link = new Node(d, cur -> link);
}

bool change(Node * h, int index = 0, double d = 0){
    bool retVal=false;
    for(int i=0;i<index && h->link ;i++, h=h->link);
    if(h->link){ h->link->data=d;retVal=true;}
    return retVal;
}
bool insert(Node*h,int index = 0, double d=0){
  bool retVal=false;
  for(int i=0;i<index && h->link ;i++, h=h->link);
  if(h->link){ h->link=new Node(d,h->link);retVal=true;}
  return retVal;
}
//bool remove(Node*h,int index=0)
int main(){
  Node head;
  for(int i=0;i<10;i++)
    append(&head,i+6);
  append(head.link->link,56);
  i_here(&head,45);
  insert(&head,2,999);
  print(head.link);
  cout<<endl<<endl;
  print(head.link);
}
