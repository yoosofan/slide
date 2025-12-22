#include <iostream>
using namespace std;
void print(double *pa);
void input(double *pa);
double* getMemory();
void f1();//myArray/100880
int main(){f1();}
double* getMemory()
{return new double[10];}
void print(double *pa){
  for(auto i = 0; i < 5; i++)
    cout << "pa[" << i <<
	  "]: " << pa[i] << endl;
}
void input(double *pa){
  for(auto i = 0; i < 5 ; i++)
    pa[i] = i+1;
}
void f1(){
  double *px = getMemory();
  input(px);  print(px);
}
