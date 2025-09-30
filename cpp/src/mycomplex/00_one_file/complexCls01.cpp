#include<iostream>
using namespace std;
struct complexCls{
  double re,img;
  void setRe(double r)
  {re=r;}
  void setImg(double i)
  {img=i;}
  double getRe(void)
  {return re;}
  double getImg(void)
  {return img;}
};
void f1(){
  complexCls c1;
  c1.re=12;
  c1.setRe(12);
  c1.setImg(4);
  cout << c1.getRe() << endl;
}
int main(){f1();}