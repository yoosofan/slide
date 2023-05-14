#include<iostream>
using namespace std;

class Node{ 
    public: 
    int data; 
    Node *next = nullptr;
};

class list{ 
    Node *head = nullptr;
    public: 
    void dispAll(void){
        Node * pn = head;
        if(!pn) cout<<"List is empty"<<endl;
        for( ; pn; pn = pn->next) 
            cout<<pn->data<<endl;
    }
    bool remove(int n){
        bool retVal = false;
        Node * pn = head, * pv = nullptr;
        if(head) 
            if(n == 0){ 
                head = head -> next; 
                delete pn; 
                retVal = true;
            }
            else{
                int i;
                for(i=0; i<n && pn; pn = pn -> next , i++)
                    pv = pn;
                // cout << __LINE__ << " line: "<< i << endl;
                if(i == n && pn){
                    
                     pv -> next = pn -> next;
                     delete pn;
                     retVal = true;
                }
            }
    return retVal;
  }
  bool insert(int n , int d){
    Node *pn=head;int i; Node *pv; bool retVal=true;
    for(i=0; i<n && pn ; i++,pn=pn->next)  pv=pn;
    if(i==n)
      if(head)
        if(n!=0)
        { pv->next=new Node;     pv=pv->next;  }
        else pv=head=new Node;
      else if(n==0)              pv=head=new Node;
      else                       retVal=false;
    else                         retVal=false;
    if(retVal)
    {   pv->next=pn;    pv->data=d;  }
    return retVal;
  }
};
int main(){  
    list l1;
    l1.insert(0,3); 
    l1.insert(1,4);
    l1.insert(0,7); 
    l1.insert(2,12);  
    l1.insert(4,18);
    l1.dispAll();   
    cout<<endl; 
    //cout<< endl << "l1.remove(1) : " << l1.remove(1) << endl;; 
    l1.remove(4); 
    l1.dispAll();   
    return 0;
}
