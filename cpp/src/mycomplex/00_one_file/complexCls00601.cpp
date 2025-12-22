#include<iostream>
using namespace std;
class complexCls{
  double re,img;
 public:
  complexCls(double r=0,double i=0):re(r), img(i){}
  double getRe(){return re;}
  double getImg(){return img;}
};
void f1(){
  complexCls c1(12, 14);
  cout << c1.getRe() << endl;
}
int main(){f1();}
