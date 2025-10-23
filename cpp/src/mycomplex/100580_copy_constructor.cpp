#include <iostream>
using namespace std;
struct myComplex{//mycomplex/100580
  double re=0, img=0;
  myComplex(const double a = 0,
            const double b = 0)
  {re = a; img = b;}
  myComplex(const myComplex&c){
    re=c.re; img=c.img;
    cout<<"copy constructor"<<endl;
  }
  void print(){cout<<'('<<re<<","
         << img << ')' << endl;
  }
  void input(){
    cout<<"Enter real: ";cin>>re;
    cout<<"Imaginary: ";cin>>img;
  }
  myComplex add(const myComplex& a){
    myComplex r = a;  r.re  += re;
    r.img += img;  return r;
  }
  myComplex sub(const myComplex& a){
    myComplex r; r.re = re - a.re;
    r.img = img - a.img; return r;
  }
  myComplex mul(const myComplex& a){
    myComplex r;
    r.re = re * a.re - img * a.img;
    r.img = img * a.re + re * a.img;
    return r;
  }
};
int main(){myComplex a(2,3),b=a,c(a);
  c=a.add(b); c=a.add(2);c.print();
  c = a.sub(b);c.print();c=a.mul(b);
  c.print();
}/* copy constructor
copy constructor
copy constructor
copy constructor
(4,3)
(0,0)
(-5,12)*/