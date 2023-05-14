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
void append(Node h,double d=0){
  Node *cur=h.link;
  for(;cur->link;cur=cur->link);
  cur->link=new Node(d);
}
int main(){
  Node head;
  for(int i=0;i<10;i++)
    append(head,i+6);
  print(head.link);
  return 0;
}
