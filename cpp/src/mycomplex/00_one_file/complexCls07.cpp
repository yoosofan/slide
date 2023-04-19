#include<iostream>
using namespace std;
class complexCls{
  double re,img;
  public:
  complexCls(double r=0,double i=0){img=i;re=r;}
  double getRe(void){return re;}
  void setRe(double r){re=r;}
  double getImg(void){return img;}
  ~complexCls()
  {cout<<"destructor: "<<re<<"  "<<img<<endl;}
};
void f1(void){
  complexCls c1(12,14);
  cout<<c1.getRe()<<endl;
  int i=0;
  if(!i){complexCls c2; c2.setRe(5);}
  if(i){complexCls c2(3);}
  else{complexCls c2(9);}
}
int main(){f1();}/*
12
destructor: 5  0
destructor: 9  0
destructor: 12  14 */