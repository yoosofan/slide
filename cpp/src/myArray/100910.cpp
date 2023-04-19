#include <iostream>
using namespace std;
void print(double *pa);
void input(double *pa);
double* getMemory2(void);
void getMemory1(double**pa);
void getMemory3(double*& pa);
void f1(void);
int main() // myArray/100910
{f1();  return 0;}
void getMemory1(double** pa)
{*pa = new double[10];}
void getMemory3(double*& pa)
{pa = new double[10];}
double* getMemory2(void)
{return new double[10];}
void print(double *pa){
  for(auto i = 0; i < 5; i++)
    cout << "pa[" << i << "]: " 
      << pa[i] << endl;
}
void input(double *pa){
  for(auto i = 0; i < 5; i++)
    pa[i] = i+1;
}
void f1(void){
  double *px = nullptr ;
  getMemory1(&px);
  double* px2 = getMemory2();
  input(px);
  print(px);
  input(px2);
  print(px2);
  double *px3 = nullptr ;
  getMemory3(px3);
  input(px3);
  print(px3);
}
