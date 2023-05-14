#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
class list{
    Node * head = nullptr;
    // Node head;
    public:
    void dispAll(void){
        Node * pn = head;
        if(!pn)
            cout << "List is empty" << endl;
        for( ; pn ; pn = pn->next )
            cout << pn->data << endl;
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
};
int main(){
    list l1;
    l1.insert(0, 3);
    l1.insert(1, 4);
    l1.dispAll();
    l1.insert(0, 7);
    l1.insert(2, 12);
    l1.insert(4, 18);
    cout<<endl;
    l1.dispAll();
    return 0;
}
