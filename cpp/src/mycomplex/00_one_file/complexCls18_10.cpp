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
  complexCls(const complexCls& a)
  {re=a.re;img=a.img;cout<<"cop"<<endl;}
  double getRe(void)
  {return re;}
  double getImg(void)
  {return img;}
  void setRe(double a)
  {re = a;}
  ~complexCls()
  {cout << "destructor:"; print();}
  void print(void){
    cout << '(' << re << ',' 
      << img << ')' << endl;
  }
};
void f4(complexCls);
complexCls f2(complexCls);
int main(){
  complexCls c1(1, 2);
  f4(c1);  
}
complexCls f2(complexCls p){
  p.print();
  p.setRe(16);
  return p;
}
void f4(complexCls p1){
  p1.print();
  complexCls p2(3, 4);
  complexCls p3(5, 6);
  p3 = f2(p2);  
  p3.print();  
}/* ./a.out
constructor:(1,2)
cop
(1,2)
constructor:(3,4)
constructor:(5,6)
cop
(3,4)
cop
destructor:(16,4)
destructor:(16,4)
(16,4)
destructor:(16,4)
destructor:(3,4)
destructor:(1,2)
destructor:(1,2)  */