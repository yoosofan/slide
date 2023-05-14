#include<iostream>
using namespace std;

struct Node{
    double data;
    Node * link = nullptr;
    Node(double d = 0, Node * link = nullptr){
        this -> data = d;
        this -> link = link;
    }
    ~Node(){
        if(link){
            cout<< data << '\t';
            delete link;
        }
        else 
            cout << data << endl;
    }
};

void print(Node * h){
    if( h ){
        cout << h -> data << '\t';
        print(h -> link);
    }
    else 
        cout << endl;
}  
int main(){
    Node head;
    head.link = new Node(2);
    Node * cur=head.link;
    cur->link = new Node(3);
    cur=cur->link;
    cur->link = new Node(6);  
    cur = cur->link;
    cur->link = new Node(22);  
    print(head.link);
    return 0;
}
