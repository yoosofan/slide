#include <iostream>
using namespace std;
struct myComplex{ // 100580
  double re, img;
  myComplex(const double a = 0, 
            const double b = 0)
  {re = a; img = b;}
  myComplex(const myComplex&c){
    re=c.re; img=c.img;
    cout << "copy constructor"
         << endl;
  }
  void print(void){ 
    cout << '(' << re << ", " 
         << img << ')' << endl; 
  }
  void input(void){
    cout << "Enter real "; cin >> re;
    cout << "Enter imaginary ";cin >> img;
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
void myFunction(void){
  myComplex a(2, 3), b=a, c(a);
  c = a.add(b); c = a.add(2);
  c.print();  a.input();
  c = a.sub(b);// c = a - b
  c.print();  b.input();
  c = a.mul(b);// c = a * b
  c.print();
}
int main(){myFunction();return 0;}/*
copy constructor
copy constructor
copy constructor
copy constructor
(4, 3)
Enter real 2
Enter imaginary 3
(0, 0)
Enter real 4
Enter imaginary 5
(-7, 22)
*/

