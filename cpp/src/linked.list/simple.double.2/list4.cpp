#include<iostream>
using namespace std;
struct Node{
    double data;
    Node * link = nullptr;

    Node(double d = 0, Node * link = nullptr){
        this -> data = d;
        this -> link = link;
    }

  ~Node(){delete link;}
};

void print(Node*h){
    if(h){
        cout << h -> data << '\t';
        print(h -> link);
    }
    else
        cout << endl;
}
void append(Node * h, double d = 0){
    for(;h -> link; h = h -> link)
        ;
    h -> link = new Node(d);
}

int main(){
    Node head;
    head.link = new Node(2);
    Node * cur = head.link;
    for(int i=0; i < 10; i++, cur = cur -> link)
        cur -> link = new Node(i+6);
    print(head.link);
}
