#include <iostream>
using namespace std;
void f1();
int main(){f1();}
void f1(){
  double *px;
  px = new double[10];
  for(auto i = 0; i < 5 ; i++)
    px[i] = i+1;
}
