#include<iostream>
using namespace std;
class A{
  int a1;
  friend void print(A);  //A(){}
public:
  A(int a):a1(a){}
  virtual void Show(void)
  { cout << a1 << endl; }
};
class B{
  int b1;
  friend void print(A);
public:
  B(int b){b1=b;}
  virtual void Show(void)
  {cout << b1 << endl;}
};
class D: public A, public B{
  //int d1;    //int b1;
  int b1;
  static int si;
public:
  static void printHello(void)
  {cout << "Hello world" << si << endl;}
  D(int a, int b, int d):A(a), B(b){b1 = d;}
  virtual void Show(void){
      A::Show();
      B::Show();
      cout << "\tb1:   " << b1 << endl;
  }
};
void print(A a1){
    cout << a1.a1 << endl;
    B b4(3);
    cout << b4.b1 << endl;
}
void myPrint(A a1){a1.Show();}
void myPrint(B a1){a1.Show();}
class C {
  int i;
public:
  C(){ i = 0; }
  void Show(void){ 
    int i = 7; 
    cout << i <<"   " << this->i << endl;
  }
};
static int GLOBAL_VARIABLE_I=12;
int D::si = 7;
int main(){
  A a1(2);  myPrint(a1);
  B b1(9);  myPrint(b1);
  C c1;     myPrint(b1);
  D d1(2, 3, 4); d1.Show();
  a1.Show();     D::printHello();
  int GLOBAL_VARIABLE_I = 15;
  cout << "i: " << GLOBAL_VARIABLE_I << endl;
  cout<<"External i "<<::GLOBAL_VARIABLE_I<<endl;
  print(a1);
}
