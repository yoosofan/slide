#include<iostream>
using namespace std;
template<class T>
class myStack{T *a; int top,n;
 public:
  myStack(){top=-1;a=new T[n=100];}
  void push(T b){if(this->isFull()) throw  1; a[++top]=b;}
  T pop(void){if(isEmpty()) throw 2; return a[top--];}
  bool isFull(void){return top==n-1;}
  bool isEmpty(void){return top==-1;}
  T Top(void){if(isEmpty()) throw 2; return a[top];}
  ~myStack(){delete[] a;a=0;n=0;}
  void printAll(void)
  {cout<<"print all"<<endl;for(int i=0;i<=top;i++)cout<<a[i]<<endl;}
};
void f1(void){myStack<int> st1;myStack<double> st2;
  st1.push(2);st1.push(3); st1.push(4);st1.printAll();
  cout<<st1.pop()<<endl;
  cout<<st1.pop()<<endl;
  cout<<st1.Top()<<endl;
  cout<<st1.Top()<<endl;
  st1.printAll();
  st2.push(2.1);st2.push(3.1);st2.push(4.5);
  st2.printAll();
}
void errorMessage(int errorNumber){
  switch(errorNumber){
    case 1:
      cout<<"Stack is full"<<endl;
    break;
    case 2:
      cout<<"Stack is empty"<<endl;
    break;
    default:
      cout<<"Another error"<<endl;
    break;
  }
}
int main(){
  try{
    f1();
  }catch(int &exc)
  {cout<<"Exception ";errorMessage(exc);}
  return 0;
}
