#include <iostream>
using namespace std;
class myArray{ // 102150
  static const int MAX = 100;
  double a[MAX]; int n; public:
  double get(const int index = 0 ){
    if(index < n) return a[index];
    cout << "Error: get myArray element"
      << endl;
    return 0;
  }
  void set(const int index,
           const double value){
    if( index < n ) a[index] = value;
    else
      cout << "Error set myArray element"
          << endl;
  }
  myArray(const double* ma=nullptr,
          int k = 0){
    if( k > MAX )
      k = MAX ;
    for(n = k--; k >= 0; k--)
      a[k] = ma[k];
  }
  myArray(const myArray& b){
    cout << "copy construcotr" << endl;
    n = b.n;
    for(int i = 0; i < n; i++) a[i] = b.a[i];
  }
  ~myArray(){cout << "Destructor" << endl;}
  void print(void){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = "
        << a[i] << endl;
  }
};
void f1(void); void f2(myArray&);
int main(){f1(); return 0;}
void f1(void){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x)/sizeof(double));
  myArray p(d);
  cout << "before call f2" << endl;
  f2(p);
}
void f2(myArray& k){k.print();}/*
copy construcotr
before call f2
 n = 4
a[0] = 10
a[1] = 12
a[2] = 34
a[3] = 54
Destructor
Destructor  */
