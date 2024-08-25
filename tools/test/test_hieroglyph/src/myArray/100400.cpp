#include <iostream>
using namespace std;
struct myArray{
  double a[100];
  int n;
  void set(double ma[], int k){
    n = k;
    for(int i = 0; i < n; i++)
      a[i] = ma[i];
  }
  void print(void){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = " << a[i] << endl;
  }
};
void f1(void);
int main(){
  f1();
  return 0;
}
void f1(void){
  double x[] = {10, 12, 34, 54};
  myArray d;
  d.set(x, 4);
  d.print();
}
