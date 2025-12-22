#include<iostream>
using namespace std;
class complexCls{
  double re=0, img=0;
  public:
  complexCls(const double r = 0,
      const double i=0){
    img = i; 
    re = r;
    cout << "constructor:"; 
    print();
  }
  double getRe(){return re;}
  double getImg(){return img;}
  ~complexCls(){
    cout << "destructor:" ; 
    print();
  }
  void print(){
    cout << '(' << re << ',' << img 
      << ')' <<endl;
  }
};
void f1(){
  complexCls c1(12,14);
  c1.print();  
  int i=0;
  if(!i){complexCls c2(5);}
  if(i){complexCls c3(3);}
  else{complexCls c4(9);}
}
complexCls* f2(){
  complexCls *pc;
  pc=new complexCls(2,4);
  return pc;
}
void f3(complexCls *p1){delete p1;}
void f4(){ 
  complexCls *p2;
  p2=f2(); //p2->re=65;
  p2->print(); f3(p2);
  //p2 = nullptr;
}
int main(){ complexCls c1(34,21);
  f1(); f4();
}/*
constructor:(34,21)
constructor:(12,14)
(12,14)
constructor:(5,0)
destructor:(5,0)
constructor:(9,0)
destructor:(9,0)
destructor:(12,14)
constructor:(2,4)
(2,4)
destructor:(2,4)
destructor:(34,21) */