#include <iostream>
using namespace std;
double* f1(void);
void f2(double* a);
double* f3(void);
void f4(double* a);
int main(){ // 100810
  double* pa = f1();
  f2(pa);
  pa = f3();
  f4(pa);
}
double* f1(void){
  double* px = nullptr;
  px = new double[10];
  return px;
}
void f2(double* a){
  delete[] a;
  a = nullptr; // ???
}
double* f3(void){
  return new double;
}
void f4(double* a){
  delete a;
  a = nullptr; // ???
}