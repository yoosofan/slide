#include<iostream>
using namespace std;
struct complexCls{
 private:
  double re,img;
 public:
  complexCls(double r=0,double i=0)
  {img=i;re=r;}
  double getRe(){return re;}
  double getImg(){return img;}
};
void f1(){
  complexCls c1(12,14); // c1.re=2; //Error
  cout<<c1.getRe()<<endl;
}
int main(){f1();return 0;}
