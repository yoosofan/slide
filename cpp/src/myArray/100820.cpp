#include <iostream>
using namespace std;
void f1(void);
int main(){
  f1();
  return 0;
}
void f1(void){
  double *px;
  px = new double[10];
  for(auto i = 0; i < 5 ; i++)
    px[i] = i+1;
}
