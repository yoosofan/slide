//Student suggestion
#include<iostream>
using namespace std;
class myStack{
  int a[100];
  int top;
 public:
  myStack(){top=0;}
  void push(int b){a[top++]=b;}
  int pop(void){return a[top--];}
  bool isFull(void){return top==100;}
  bool isEmpty(void){return --top==0;}
};
int main(){
  myStack st1;
  st1.push(2);
  cout<<st1.pop()<<endl;
  return 0;
}
