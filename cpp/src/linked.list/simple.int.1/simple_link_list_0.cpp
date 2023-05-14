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
  return 0;
}
