#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
};
class list{
    Node * head = nullptr;
    public:
    static int value;
    void displayAll(void){
        Node * pn = head;
        if(!pn)
            cout << "List is empty" << endl;
        for(; pn; pn=pn->next)
            cout << pn->data << endl;
    }

    int & operator[](int n){
        Node * pn = head;
        int i;
        Node * pv;
        int & retVal = value;
        for(i = 0; i < n && pn; i++, pn = pn->next)
            pv = pn;
        if(i == n)
            if(head)
                if(n != 0){
                    pv->next = new Node;
                    pv = pv->next;
                }
                else
                    pv = head = new Node;
            else if(n == 0)
                pv = head = new Node;
            else
                throw 2; //retVal = false;
        else
            throw 2; //retVal = false;
        return pv -> data;
  }
};
int list::value=0;
void myFunction(void){
    list l1;
    l1[0] = 2;
    l1[1] = 3;
    l1[2] = 4;
    l1.displayAll();
}

int main(){
    try{
        myFunction();
    } catch(...){
        cout << "exception" << endl;
    }
    return 0;
}
