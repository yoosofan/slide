#include <iostream>
using namespace std;
void print(double* pa);
void input(double* pa);
void f1();
int main(){
  f1();
  return 0;
}
void print(double* pa){
  for(auto i = 0; i < 5; i++)
    cout << "pa[" << i << "]: " << pa[i];
}
void input(double* pa){
  for(auto i = 0; i < 5 ; i++)
    pa[i] = i+1;
}
void f1(){
  auto* px = new double[10];
  auto  px2 = new double[10];
  input(px);
  print(px);
  delete[] px;
  delete[] px2;
}
