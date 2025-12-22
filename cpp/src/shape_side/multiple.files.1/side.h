#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class side{
  unsigned d;
  public:
  side()=default;
  side(int a){
    if(a<=0){cout<<"Side of a shape connot be negative or zero"<<endl;exit(0);}
    d=a;
  }
  side(const side&a){static int counter=0;counter+=1;
    this->d = a.d;cout<<counter<<"\tcopy constructor:"<<d<<endl;
  }
  void input(){
    cout<<"Enter length of side:"; cin>>d;
    while(d<=0){
      cout<<"Side must be >0"<<endl;
      cout<<"Enter length of side:"; cin>>d;
    }
  }
  side operator+(side a){
    side b;
    //side b(*this); // b(a)
    b.d = this->d + a.d;
    this->show();cout<<" + "<<endl;
    return b;
  }
  bool operator>(side a){cout<<d<<" > "<<a.d<<endl; return d>a.d;}
  void show(){cout<<d;}
};
