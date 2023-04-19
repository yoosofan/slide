#include<iostream>
using namespace std;
struct complexCls{
  double re,img;
  void setRe(double r){re=r;}
  void setImg(double i){img=i;}
  double getRe(void){return re;}
  double getImg(void){return img;}
};
void f1(void){
  //complexCls c1=2; // Error
  //complexCls c1(2,3); // Error
  complexCls c1{2,3};
  cout<<c1.getRe()<<"  "<<c1.getImg()<<endl;
  c1.re=12;
  c1.setRe(12);
  c1.setImg(4);
  cout<<c1.getRe()<<endl;
}
int main(){f1();return 0;}
