#include<iostream>
using namespace std;
struct complexCls{
  double re,img;
  complexCls(double r=0,double i=0)
  {img=i;re=r;cout<<re<<endl;}
  //complexCls(double r=0,double i)
  //{img=i;re=r;}//Error
  double getRe(void){return re;}
  double getImg(void){return img;}
};
void f1(void){
  complexCls c1(12,14);
  complexCls c2 = 12;
  c2 = 992;
  complexCls c3(12);
  complexCls c4(12, 0);
  complexCls c5;
  complexCls c6 = 0;
  complexCls c7(0);
  complexCls c8(0, 0);
  cout << c1.getRe() << endl;
}
int main(){f1();return 0;}
