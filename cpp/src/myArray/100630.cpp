#include <iostream>
using namespace std;
struct myArray{ //100630
  static const int MAX = 100;
  double a[MAX];
  int n;
  myArray(const double* ma = nullptr, int k = 0){
    if( k > MAX ) 
      k = MAX ;
    for(n = k--; k >= 0; k--)
      a[k] = ma[k];
  }
  void print(){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = " << a[i] << endl;
  }
};
void f1();
int main(){f1();}
void f1(){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x) / sizeof(double));
  d.print();
}
