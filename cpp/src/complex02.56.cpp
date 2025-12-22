#include<iostream>
using namespace std;
struct complexCls{
  double re = 0, img = 0;
  void set(const double& r=0, 
    const double& i=0)
  {re=r;img=i;}
  double getRe()const {return re;}
  double getImg()const {return img;}
  void setRe(const double& r){re = r;}
  void setImg(const double& i){img = i;}
  void print() const {
    cout << '(' << re << ','
      << img << ')' << endl;
  }
  void input(){
    cout << "Enter re "; cin >> re;
    cout << "Enter img "; cin >> img;
  }
};
void f1(complexCls& c1){
  c1.setRe(13);
  c1.print();
  c1.set(13, 17);
  c1.print();
}
int main(){
  complexCls c1;
  f1(c1);
  return 0;
}