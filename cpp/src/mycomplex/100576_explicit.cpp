// Error
#include <iostream>
using namespace std;
struct myComplex{ // 100575
  double re, img; // explicit
  explicit myComplex(const double a = 0, 
            const double b = 0){ 
    re = a; 
    img = b;
  }
  void print(void){ 
    cout << '(' << re << ", " 
         << img << ')' << endl; 
  }
  void input(void){
    cout << "Enter real ";
    cin >> re;
    cout << "Enter imaginary ";
    cin >> img;
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
    r.re = re * a.re - img * a.img;
    r.img = img * a.re + re * a.img;
    return r;
  }
};
int main(){
  myComplex a(2, 3), b(4), c;
  myComplex d = 4;
  c = a.add(b); 
  c = a.add(2);
  c.print();
  a.input();
  c = a.sub(b);// c = a - b
  c.print();
  b.input();
  c = a.mul(b);// c = a * b
  c.print();
  c.print();
  return 0;
}
