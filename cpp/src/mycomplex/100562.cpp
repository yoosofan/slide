#include <iostream>
using namespace std;
class myComplex{ // 100562
  double re, img;
  public:
  myComplex(double a = 0, double b = 0){ 
    re = a; 
    img = b;
  }
  void print(){ 
    cout << '(' << re << ", " 
         << img << ')' << endl; 
  }
  void input(){
    cout << "real part ";
    cin >> re;
    cout << "Enter imaginary part ";
    cin >> img;
  }
  myComplex add(myComplex a){
    myComplex r = a;
    r.re  += re;
    r.img += img;
    return r;
  }
  myComplex sub(myComplex a){
    myComplex r;
    r.re = re - a.re;
    r.img = img - a.img;
    return r;
  }
  myComplex mul(myComplex a){
    myComplex r;
    r.re = re * a.re - img * a.img;
    r.img = img * a.re + re * a.img;
    return r;
  }
};
void myFunction(){
  myComplex a(2, 3), b(4), c; 
  // b(4, 0), c(0, 0);
  c = a.add(b); 
  c = a.add(2);// 2+2.3
  // c = a + 2; // i+x
  // (double)i + x
  c.print();
  a.input();
  c = a.sub(b); 
  // c = a - b
  c.print();
  b.input();
  c = a.mul(b); 
  // c = a * b
  c.print();
}
int main(){
  myFunction();
  return 0;
}
