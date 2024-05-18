#include<iostream>
using namespace std;
class myStack{
  int a[100];
  int top = -1;
 public:
  // myStack(){top=-1;}
  void push(int b){
    if(this->isFull()) 
      throw  1; 
    a[++top] = b;
  }
  int pop(){
    if(isEmpty()) 
      throw 2; 
    return a[top--];
  }
  bool isFull()
  {return top==99;}
  bool isEmpty()
  {return top==-1;}
};
int main(){
  myStack st1;
  st1.push(2);
  st1.push(3);
  st1.push(4);
  cout<<st1.pop()<<endl;
  cout<<st1.pop()<<endl;
  cout<<st1.pop()<<endl;
  /*cout<<st1.pop()<<endl;
  cout<<st1.pop()<<endl;
  cout<<st1.pop()<<endl;*/
}
