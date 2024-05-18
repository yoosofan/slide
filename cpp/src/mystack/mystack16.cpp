#include<iostream>
using namespace std;
struct student{
  string name, stdNumber;
  double average;
};
ostream& operator<<(ostream &o1, const student &st1){
  o1 << st1.name << '\t' << st1.stdNumber << '\t' << st1.average;
  return o1;
}
template<typename T> class myStack{
  T *a=nullptr; 
  int top=-1, n=0;
 public: 
  myStack(){top=-1;a=new T[n=1];}
  void push(T b){
    if(this->isFull()){
      T *m1=new T[2*n];
      if(m1==nullptr){
        throw 1;
      }else{
        for(int i=0;i<n;i++)
          m1[i]=a[i];
        delete[]a;     
        a=m1; 
        n*=2;
        cout<<"In renew allocation"<<endl;
      }
    }
    a[++top]=b;
  }
  T pop(){
    if(isEmpty()) 
      throw 2; 
    return a[top--];
  }
  bool isFull()
  {return top==n-1;}
  bool isEmpty()
  {return top==-1;}
  T Top(){
    if(isEmpty()) 
      throw 2; 
    return a[top];
  }
  ~myStack()
  {delete[] a;a=nullptr;n=0;}
  void printAll(){
    cout << "print all" << endl;
    for(int i=0;i<=top;i++)
      cout << a[i] << endl;
  }
};
void f1(){
  myStack<int> st1;
  myStack<double> st2;
  st1.push(2);
  st1.push(3); 
  st1.push(4);
  st1.printAll();
  cout << st1.pop() << endl;
  cout<<st1.pop()<<endl;
  cout<<st1.pop()<<endl;  
  cout<<st1.pop()<<endl;
  cout<<st1.Top()<<endl;  
  cout<<st1.Top()<<endl;
  st1.printAll();
  st2.push(2.1);
  st2.push(3.1);
  st2.push(4.5);  
  st2.printAll();
  myStack<student> st3;
  student ms1{"Kamran","23234",15.3};
  st3.push(ms1);  
  cout<<st3.pop()<<endl;
}
void errorMessage(int errorNumber){
  switch(errorNumber){
    case 1:cout<<"Memory allocation error"<<endl;break;
    case 2:cout<<"Stack is empty"<<endl;   break;
    default:cout<<"Another error"<<endl;   break;
  }
}
int main(){
  try{f1();}catch(int exc)
  {cout<<"Exception ";errorMessage(exc);}
}