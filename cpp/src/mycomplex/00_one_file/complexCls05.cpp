//Error
#include<iostream>
using namespace std;
struct complexCls{
 private:
  double re,img;
  complexCls(double r=0,double i=0)
  {img=i;re=r;}
 public:
  double getRe(void){return re;}
  double getImg(void){return img;}
};
void f1(void){
  complexCls c1(12,14);
  cout<<c1.getRe()<<endl;
}
int main(){f1();return 0;}
