#include<iostream>
using namespace std;
struct complexCls{
 private:
  double re=0,img=0;
 public:
  complexCls()=delete;
  complexCls(double r,double i=0){img=i;re=r;}  
  double getRe(void){return re;}
  double getImg(void){return img;}
};
void f1(void){
  complexCls c1(12,14);
  //complexCls c1;
  cout<<c1.getRe()<<endl;
}
int main(){f1();return 0;}
