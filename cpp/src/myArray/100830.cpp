// Error
#include <iostream>
using namespace std;
void f1(void);
int main(){
  f1();
  return 0;
}
void f1(void){
  auto *px;  // Error
  px = new double[10];
  for(auto i = 0; i < 5 ; i++)
    px[i] = i+1;
}
/*
  g++ 100830.cpp 
  100830.cpp: In function ‘void f1()’:
  100830.cpp:10:3: error: declaration of 
  ‘auto* px’ has no initializer
     10 |   auto *px;  // Error
        |   ^~~~
*/