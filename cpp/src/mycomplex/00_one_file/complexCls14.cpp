#include<iostream>
using namespace std;
class complexCls{
  double re = 0, img = 0;
  public:
  complexCls(const double r = 0, 
      const double i = 0){
    img = i;
    re = r;
    cout << "constructor: ";
    print();
  }
  double getRe(void) {return re;}
  double getImg(void){return img;}
  void setRe(double a){re = a;}
  void setImg(double a){img = a;}
  ~complexCls(){
    cout << "destructor: ";
    print();
  }
  void print(void){
    cout << '(' << re << ',' << 
      img << ')' << endl;
  }
};
complexCls* f2(void){
  complexCls* pc;
  pc = new complexCls(2,4);
  return pc;
}
void f3(complexCls* p1){
  delete p1;
  p1 = nullptr;
  // p1 -> print();
}
void f4(void){
  complexCls* p2 = f2();  
  p2->print();  
  f3(p2);
  p2 = new complexCls[20];
  p2[0].setRe(22);  
  p2[0].setImg(21);
  p2[1].setRe(32);  
  p2[1].setImg(31);
  int i;
  for(i=0;i<2;i++)   
    p2[i].print();
  delete[] p2;
}
int main()
{complexCls c1(34,21);f4();}
