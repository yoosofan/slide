#include <iostream>
using namespace std;
void f1();
int main(){
  f1();
}
void f1(){
  auto *px = new double[10];
  auto px1 = new double[10];
  for(auto i = 0; i < 5 ; i++)
    px[i] = i+1;
  auto x1 = 0.0;
  cout << x1 << endl;
  cout << 1/2 << endl;
  cout << 1.0/2.0 << endl;
  cout << 1.0/2 << endl;
  cout << 1/2.0 << endl;
  delete[] px;
  delete[] px1;
}
