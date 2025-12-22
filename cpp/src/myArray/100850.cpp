#include <iostream>
using namespace std;
void f1();
int main(){
  f1();
  return 0;
}
void f1(){
  auto *px = new double[10];
  for(auto i = 0; i < 5 ; i++)
    px[i] = i+1;
  for(auto i = 0; i < 5; i++)
    cout << "px[" << i << "]: " << px[i];
  auto s1 = "salam";
}
