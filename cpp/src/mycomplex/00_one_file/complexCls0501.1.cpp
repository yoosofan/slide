// Error 
#include<iostream>
using namespace std;
struct complexCls{
 private:
  double re,img;
  complexCls(double r,double i=0){img=i;re=r;}
 public:
  complexCls()=default;
  double getRe(void){return re;}
  double getImg(void){return img;}
};
void f1(void){
  //complexCls c1(12,14);
  complexCls c1;
  complexCls c2(1);
  complexCls c3(2, 4);
  cout<<c1.getRe()<<endl;
}
int main(){f1();return 0;}
