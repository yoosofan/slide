#include<iostream>
using namespace std;
class myStack{
  int a[100];
  int top = 0;
 public:
  void push(int b){a[top++]=b;}
  int pop(){return a[top--];}
  bool isFull(){return top==100;}
  bool isEmpty(){return top-1==0;}
};
int main(){
  myStack st1;
  st1.push(2);
  cout<<st1.pop()<<endl;
}
