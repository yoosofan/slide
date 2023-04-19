#include<iostream>
using namespace std;
struct complexCls{
  double re, img; // No Default
  void set(double r=0,double i=0)
  {re=r;img=i;}
  void print(void){
    cout << '(' << re << ','
      << img << ')' << endl;
  }
  void input(void){
    cout << "Enter re "; cin >> re;
    cout << "Enter img "; cin >> img;
  }
};
void f1(complexCls c1){
  c1.re=12;
  c1.print();
  c1.set(12,14);
  c1.print();
}
int main(){
  complexCls c1;
  f1(c1);
}