#include<iostream>
using namespace std;
class complexCls{//ERROR
  double re = 0, img = 0;
  long double ar[20000];
  public:
  complexCls(double r = 0, double i = 0){
    img = i;re = r;
    cout<<"constructor: "; print();
  }
  double getRe(void){return re;}
  double getImg(void){return img;}
  ~complexCls()
  {cout<<"destructor: "; print();}
  void print(void){
    cout<<'('<<re<<','<<img<<')'<<endl;
  }
};
complexCls* f2(void){
  complexCls *pc;
  pc=new complexCls(2,4);
  delete pc;
  return pc;
}
void f3(complexCls *p1){delete p1;}
void f4(void){
  complexCls* p2 = f2();
  cout << "Before print" << endl;
  p2->print();
  cout << "After print" << endl;//f3(p2);
}
int main(){f4();}