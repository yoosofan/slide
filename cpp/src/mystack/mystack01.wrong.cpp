#include<iostream>
using namespace std;
class myStack{
  int a[100];
  int top;
 public:
  void push(int b){
    a[top++]=b;
  }
  int pop(void){
    return a[top--];
  }
};
int main(){
  myStack st1;
  st1.push(2);
  cout<<st1.pop()<<endl;
  return 0;
}
