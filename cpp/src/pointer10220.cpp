#include<iostream>
using namespace std;
int main(){
  int a[100];
  const int b[] = {1,2,3,4};
  // b[2] = 4;
  int *p;
  // a = p; //Error
  // p = b;
  const int *p1;
  int const *p2;
  p2 = a;
  p1 = a;
  p2 = b;
  p1 = b;
  // *(p2+1) = 4;
  // *(p1+1) = 4;
  int * const p3 = a;
  // p3 = a;
  p3[2] = 4;
  const int * const p4 = a;
  // p4 = a;
  // p4[2]=4;
  
}