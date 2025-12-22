#include <iostream>
using namespace std;// rvalue
class myComplex{//100569 Error
  double re, img; 
  public:
  myComplex(const double a = 0,
            const double b = 0){
    re = a; 
    img = b;
  }
  myComplex(const myComplex& a){
    re = a.re; img = a.img;
    cout << "Copy Constructor" << endl;
  }
  ~myComplex(){
    cout << "Destructor" << endl;
  }
  void print() const {
    cout << '(' << re << ", " 
      << img << ')' << endl;
  }
  myComplex add(const myComplex& a){
    myComplex r = a;
    r.re  += re;
    r.img += img;
    return r;
  }
  myComplex sub(const myComplex& a){
    myComplex r;
    r.re = re - a.re;
    r.img = img - a.img;
    return r;
  }
  myComplex mul(const myComplex& a){
    myComplex r;
    r.re=re*a.re-img*a.img;
    r.img=img*a.re+re*a.img;
    return r;
  }
};
void f1(){
  myComplex a(2, 3), b(4), c;
  c = a.add(b);
  c = a.add(2);
  c.print();
  c = a.sub(b); // c = a - b
  c.print();
  c = a.mul(b); // c = a * b
  c.print();
}
int main(){f1();}/*
Copy Constructor
Destructor
Copy Constructor
Destructor
Destructor
(4, 3)
Destructor
(-2, 3)
Destructor
(8, 12)
Destructor
Destructor
Destructor*/