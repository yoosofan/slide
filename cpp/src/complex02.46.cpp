#include<iostream>
using namespace std;
struct complexCls{
  double re = 0, img = 0;
  void set(const double& r=0, const double& i=0)
  {re=r;img=i;}
  double getRe(){return re;}
  double getImg(){return img;}
  void setRe(const double& r){re = r;}
  void setImg(const double& i){img = i;}
  void print(){
    cout << '(' << re << ','
      << img << ')' << endl;
  }
  void input(){
    cout << "Enter re "; cin >> re;
    cout << "Enter img "; cin >> img;
  }
};
void f1(complexCls& c1){
  int a = 13, b = 17;
  c1.re=a;
  c1.print();
  c1.set(a, b);
  c1.print();
}
int main(){
  complexCls c1;
  f1(c1);
}