// Error
#include <iostream>
#include <cmath>
using namespace std;
class complexCls{
  double re=0,im=0;
  public:
  //explicit complexCls(double m=0 , double n=0){r=m;i=n;}
  complexCls(double m=0 , double n=0) {re=m;im=n;}
  //complexCls(int m=0 , int n=0){r=m;i=n;}
  complexCls(complexCls&a)
  {re=a.re;im=a.im; cout<<"Copy constructor"<<endl;}
  //complexCls operator+(complexCls&a)
  //{complexCls b=a; b.re+=re;b.im+=im; return b;}
  complexCls operator+(complexCls a){
    complexCls b=a; 
    b.re+=re;
    b.im+=im; 
    return b;
  }
  complexCls operator=(complexCls a){
    re=a.re;
    im=a.im;
    return *this;
  }
  ~complexCls()
  {cout<<"destructor "<<endl;}
  bool operator==(complexCls&a)
  {return re == a.re && im == a.im ;}
  bool operator!(void)
  {return !(re == 0 && im == 0);}
  void Show()
  {cout<<'('<<re<<','<<im<<')'<<'\t'<<endl;}
  double Magnitude()
  {return sqrt(re*re+im*im);}
}; 
void f1(){
  const int n=10;
  int ar[n];
  static int numberOfErrors=0;
  complexCls a(2,3);
  complexCls b(4,5);
  complexCls c=a;
  if(!c) cout<< " c is zero "<<endl;
  else  cout<< " c is not zero "<<endl;
  numberOfErrors++;
  c.Show();
  c=a+b; 
  c.Show();
  //c = a+1;
  c = a + 12;
  throw 2;
  cout<<"This will not appear"<<endl;
}
int main(){
  f1();
  cout<<"This will not appear in main"<<endl;
  return 0;
}
