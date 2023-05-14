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
        if( n > len() )
            throw 2;
        Node * pn = head;
        for(int i = 0; i < n; i++, pn = pn->next)
            ;
        return pn -> data;
    }
};
// int list::value=0;
void myFunction(void){
    list l1;
    l1.insert(0,-4);
    l1.insert(0,-3);
    l1.insert(0,-2);
    l1.insert(0,-1);
    l1.displayAll();
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
