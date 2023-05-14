#include<iostream>
using namespace std;
struct Node{
    double data;
    Node *link;
    Node(double d=0,Node*link=nullptr){
        this ->data = d;
        this -> link = link;
    }
  ~Node(){
      cout << data << endl;
  }
};

void print(Node*h){
    if(h){
        cout << h -> data << endl;
        print(h -> link);
    }
}  

int main(){
    Node head;
    head.link = new Node(2);
    Node * cur = head.link;
    delete cur;
    return 0;
}
