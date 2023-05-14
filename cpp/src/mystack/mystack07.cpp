#include<iostream>
using namespace std;
class myStack{
  int a[100];
  int top;
 public:
  myStack(){top=-1;}
  void push(int b){if(this.isFull) throw  1; a[++top]=b;}
  int pop(void){if(isEmpty) throw 2; return a[top--];}
  bool isFull(void){return top==99;}
  bool isEmpty(void){return top==-1;}
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
  cout<<st1.pop()<<endl;
  cout<<st1.pop()<<endl;
  cout<<st1.pop()<<endl;*/
  return 0;
}
