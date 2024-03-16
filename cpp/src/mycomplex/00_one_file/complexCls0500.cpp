#include<iostream>
using namespace std;
//00_one_file/complexCls0500.cpp
class complexCls{
  double re,img;
 public:
  complexCls() = default;
  complexCls(const double r,
    const double i)
  {re = r; img = i;}
  double getRe(void){return re;}
  double getImg(void){return img;}
};
void f1(void){
  complexCls c1(12,14);
  complexCls c2;
  cout << c1.getRe() << endl;
  cout << c2.getRe() << endl;
}
int main(){f1();}
