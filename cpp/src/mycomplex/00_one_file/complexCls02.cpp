#include<iostream>
using namespace std;
struct complexCls{
  double re,img;
  void setRe(double r){re=r;}
  void setImg(double i){img=i;}
  double getRe(void){return re;}
  double getImg(void){return img;}
  void set(double r=0,double i=0)
  {re=r;img=i;}
};
void f1(void){
  complexCls c1;
  c1.re=12;
  c1.setRe(12);
  c1.setImg(4);
  c1.set(12,14);
  cout<<c1.getRe()<<endl;
}
int main(){f1();}
