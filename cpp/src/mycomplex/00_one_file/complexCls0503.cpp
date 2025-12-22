// Error
#include<iostream>
using namespace std;
struct complexCls{
 private:
  double re,img;
  complexCls(double r,double i=0)
  {img=i;re=r;}
 public:
  complexCls() = default;
  double getRe(){return re;}
  double getImg(){return img;}
};
void f1(){
  complexCls c1(12, 14);
  complexCls c2;
  cout<<c1.getRe()<<endl;
  cout<<c2.getRe()<<endl;
}
int main(){f1();}
