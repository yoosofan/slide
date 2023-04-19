#include <iostream>
using namespace std;
struct myArray{
  static const int MAX = 100;
  double a[MAX];
  int n;
  myArray(double ma[], int k){
    if( k > 100 ) 
      k = 100 ;
    for(n = k--; k >= 0; k--)
      a[k] = ma[k];
  }
  void print(void){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = " << a[i] << endl;
  }
};
int main(void){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x) / sizeof(double));
  d.print();
}
