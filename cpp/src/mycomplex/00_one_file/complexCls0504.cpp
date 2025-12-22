#include<iostream>
using namespace std;
struct complexCls{
 private:
  double re=0, img=0;
  complexCls(double r){img=0;re=r;}
 public:
  complexCls() = default;
  complexCls(double r, double i){img=i;re=r;}
  double getRe(){return re;}
  double getImg(){return img;}
};
void f1(){
  complexCls c1(12, 14);
  complexCls c2;
  // complexCls c3(13);
  cout<<c1.getRe()<<endl;
  cout<<c2.getRe()<<endl;
}
int main(){f1();}
