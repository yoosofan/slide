#include<iostream>
using namespace std;
class Node{
 public: 
  int data;
  Node *next;
};
class list{
  Node *head=nullptr;
 public: 
  void displayAll(){
    cout<<"The list is empty "<<endl;
  }
};
int main(){
  list l1;
  l1.displayAll();
}
