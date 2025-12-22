#include<iostream> // Error
using namespace std;
struct complexCls{
  double re = 0, img = 0;
  void set(double& r=0, double& i=0)
  {re=r;img=i;}
  double getRe(){return re;}
  double getImg(){return img;}
  void setRe(double& r){re = r;}
  void setImg(double& i){img = i;}
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
  c1.setRe(a);
  c1.print();
  c1.set(a, b);
  c1.print();
}
int main(){
  complexCls c1;
  f1(c1);
  return 0;
}