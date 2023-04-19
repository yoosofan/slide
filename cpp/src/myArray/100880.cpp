// Error myArray/100880
#include <iostream>
using namespace std;
void print(double *pa);
void input(double *pa);
void getMemory(double*);
void f1(void);
int main(){
  f1();
  return 0;
}
void getMemory(double *pa){
  pa = new double[10];
}
void print(double *pa){
  for(auto i = 0; i < 5; i++)
    cout << "pa[" << i << "]: " << pa[i];
  
}
void input(double *pa){
  for(auto i = 0; i < 5 ; i++)
    pa[i] = i+1;
  
}
void f1(void){
  double *px = nullptr ;
  getMemory(px);
  input(px);
  print(px);
}
