#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next = nullptr;
};
class list{
    Node * head = nullptr;
    public:
    //static int value;
    void displayAll(void){
        Node * pn = head;
        if(!pn)
            cout << "List is empty" << endl;
        for(; pn; pn=pn->next)
            cout << pn->data << endl;
    }
    int len(void){
        int i=0;
        Node* cur = head;
        for(; cur ; cur = cur -> next, i++)
            ;
        return i;
    }
    bool insert(int n,int d){
        Node * pn = head;
        int i;
        Node *pv = nullptr;
        bool retVal = true;
        for( i=0; i < n && pn ; i++ , pn = pn->next)
            pv = pn;
        if(i == n)
            if(head)
                if(n != 0){
                    pv->next = new Node;
                    pv = pv->next;
                }
                else
                    pv = head = new Node;
            else
                if(n == 0)
                    pv = head = new Node;
                else
                    retVal = false;
        else
            retVal = false;
        if(retVal){
            pv->next = pn;
            pv->data = d;
        }
        return retVal;
    }
    
    int & operator[](int n){
        Node * pn = head;
        int i;
        Node *pv = nullptr;
        for( i=0; i < n && pn ; i++ , pn = pn->next)
            pv = pn;
        if(i == n)
            if(head)
                if(n != 0)
                    if( pv -> next)
                        pv = pv->next;
                    else{
                        pv -> next = new Node;
                        pv = pv -> next;
                    }
                else
                    pv = head;
            else
                if(n == 0)
                    pv = head = new Node;
                else
                    throw 2;
        else
            throw 3;
        return pv -> data;
    }
};
// int list::value=0;
void myFunction(void){
    list l1;
    l1[0] = 2;
    l1[1] = 3;
    l1[2] = 4;
    l1.displayAll();
    l1[0] = -2;
    l1[1] = -3;
    l1[2] = -4;
    l1[3] = -5;
    l1[4] = -6;
    l1.displayAll();
    l1[7] = 8;
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
