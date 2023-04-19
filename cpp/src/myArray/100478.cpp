#include <iostream>
using namespace std;
void f1(void);
int main(){
  f1(); f1(); f1();
  return 0;
}
void f1(void){
  static int static_i = 0;
  // i = 0;
  cout << "static_i: " << static_i++ << endl;
}
