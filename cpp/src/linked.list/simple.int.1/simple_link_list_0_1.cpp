#include<iostream>
using namespace std;
class Node{
 public: 
  int data;
  Node *next;
};
int main(){
  Node head;
  head.next = nullptr;
  //head.data = 12;
  head.next = new Node();
  head.next->next = nullptr;
  head.next->data = 15;
}
