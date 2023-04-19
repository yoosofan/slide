#include <iostream>
using namespace std;
struct myArray{
  static const int MAX = 100;
  double a[MAX];
  int n;
  myArray(const double ma[], int k){
    if( k< 0 || k > MAX) 
      k = MAX ;
    for(n = k--; k >= 0; k--)
      a[k] = ma[k];
  }
  void print(void){
    cout << " n = " << n << "\t MAX: " << MAX << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = " << a[i] << endl;
  }
};
int main(){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x) / sizeof(double));
  myArray b(x, sizeof(x) / sizeof(double));
  d.print();  b.a[1] = 94;  d.print();  b.print();
}
