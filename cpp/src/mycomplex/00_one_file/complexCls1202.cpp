#include<iostream>
using namespace std;
class complexCls{
  double re=0, img=0; 
  double ar[20000];
  public:
  complexCls(double r = 0, double i = 0){
    img=i;re=r;
    cout<<"constructor: ";
    print();
  }
  double getRe(){return re;}
  double getImg(){return img;}
  ~complexCls(){
    cout<<"destructor: ";
    print();
  }
  void print()
  {cout<<'('<<re<<','<<img<<')'<<endl;}
};
complexCls* f2(){
  complexCls *pc;
  pc = new complexCls(2,4);
  delete pc;
  pc = nullptr;
  return pc;
}
void f3(complexCls *p1){delete p1;}
void f4(){complexCls *p2;
  p2=f2();  // p2->print();
  cout<<"dd"<<endl; f3(p2);
}
int main(){f4();}
