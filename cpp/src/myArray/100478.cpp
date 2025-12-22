#include <iostream>
using namespace std;
void f1();
int main(){
  f1(); f1(); f1();
}
void f1(){
  static int static_i = 0;
  // i = 0;
  cout << "static_i: " << static_i++ << endl;
}
