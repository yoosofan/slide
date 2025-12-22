#include<iostream> // reference_swap22.cpp
using namespace std;
void mySwap(int& a, int& b){
  int t=a;
  a=b;
  b=t;
}
void mySwap(int a, int b){
  int t=a;
  a=b;
  b=t;
}
void f1(){
  int m = 2, n = 8;
  cout << "m: " << m << "\tn: " << n << endl;
  mySwap(m, n);
  cout << "m: " << m << "\tn: " << n << endl;
  mySwap(m, n);
  cout << "m: " << m << "\tn: " << n << endl;
}
int main(){ 
 f1();
}
