#include <iostream>
using namespace std;
void print(double* pa);
void input(double* pa);
void getMemory(double*);
void f1();// myArray/100891
int main(){f1();}// Error
void getMemory(double* pa)
{pa = new double[10];}
void print(double* pa){
  for(auto i = 0; i < 5; i++)
    cout << "pa[" << i << "]:" 
      << pa[i] << endl;
}
void input(double* pa){
  for(auto i = 0; i < 5; i++)
    pa[i] = i+1;
}
void f1(){
  double *px = nullptr;
  getMemory(px);
  input(px); print(px);
}
