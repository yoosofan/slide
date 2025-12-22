#include<iostream>
using namespace std;
class complexCls{
  double re = 0, img = 0; 
 public:
  complexCls(double r = 0, double i = 0){
    img = i;
    re = r;
    cout << "constructor:"; print();
  }
  double getRe()
  {return re;}
  double getImg()
  {return img;}
  ~complexCls()
  {cout << "destructor:"; print();}
  void print(){
    cout << '(' << re << ',' 
      << img << ')' << endl;
  }
};
complexCls* f2(){
  complexCls *pc;
  pc = new complexCls(2,4);
  return pc;
}
void f3(complexCls *p1)
{delete p1;}
void f4(){
  complexCls *p2;
  p2 = f2();  
  p2 -> print();  
  f3(p2);
  p2 = new complexCls[2]{{21,21}, {32,31}};
  for(int i = 0; i < 2; i++)    
    p2[i].print();
  delete[] p2;
}
int main()
{complexCls c1(34,21);f4();}/*
constructor:(34,21)
constructor:(2,4)
(2,4)
destructor:(2,4)
constructor:(21,21)
constructor:(32,31)
(21,21)
(32,31)
destructor:(32,31)
destructor:(21,21)
destructor:(34,21)
*/