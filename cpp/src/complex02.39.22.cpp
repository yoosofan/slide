#include<iostream>
using namespace std;
struct complexCls{
  double re = 0, img = 0;
  void set(const double r=0, const double i=0)
  {re=r;img=i;}
  double getRe(void) const
  {return re;}
  double getImg(void)const 
  {return img;}
  void setRe(const double r)
  {re = r;}
  void setImg(const double i)
  {img = i;}
  void print(void) const {
    cout << '(' << re << ','
      << img << ')' << endl;
  }
  void input(void){
    cout << "Enter re "; cin >> re;
    cout << "Enter img "; cin >> img;
  }
};
void f1(complexCls& c1){ // const?
  int a = 13, b = 17;
  c1.setRe(a);
  c1.print();
  c1.set(a, b);
  c1.print();
}
void f2(const complexCls& c1){ // const?
  c1.print();
  cout << c1.getImg() << endl;
}
int main(){
  complexCls c1;
  f1(c1);
  f2(c1);
  return 0;
}