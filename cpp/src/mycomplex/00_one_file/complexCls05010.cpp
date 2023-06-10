#include<iostream>
using namespace std;
//00_one_file/complexCls05010.cpp
class complexCls{
  double re,img;
 public:
  complexCls() = delete;
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
int main(){f1();}/*
00_one_file/complexCls05010.cpp: 
* In function ‘void f1()’:
00_one_file/complexCls05010.cpp:16:14: 
* error: 
* use of deleted function ‘complexCls::complexCls()’
   16 |   complexCls c2;
      |              ^~
00_one_file/complexCls05010.cpp:7:3: 
* note: declared here
    7 |   complexCls() = delete;
      |   ^~~~~~~~~~
*/