#include<iostream>
using namespace std;
class myStack{
  int a[100];
  int top = 0;
 public:
  // myStack(){top=0;}
  void push(int b){
    a[top++]=b;
  }
  int pop(){
    return a[top--];
  }
};
int main(){
  myStack st1;
  st1.push(2);
  cout<<st1.pop()<<endl;
}
