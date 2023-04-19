#include<iostream>
using namespace std;
class complexCls{
  double re=0,img=0;
  public:
  complexCls(double r=0,double i=0){img=i;re=r;}
  double getRe(void){return re;}
  double getImg(void){return img;}
  ~complexCls()
  {cout<<"destructor: "<<re<<"  "<<img<<endl;}
};
void f1(void){cout<<"In f1"<<endl;
  complexCls c1(12,14);
  cout<<c1.getRe()<<endl;
  int i=0;
  if(!i){complexCls c2(5);}
  if(i){complexCls c3(3);}
  else{complexCls c4(9);}
}
complexCls* f2(void){cout<<"In f2"<<endl;
  complexCls *pc;
  pc=new complexCls(2,4);
  //delete pc;
  return pc;
}
void f3(complexCls *p1){cout<<"In f3"<<endl;
  delete p1;
}
int main(){cout<<"In main()"<<endl;
  complexCls c1(34,21);
  f1();f3(f2());
}
