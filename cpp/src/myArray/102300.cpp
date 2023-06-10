#include <iostream>
using namespace std;
class myArray{ // 102300
  static const int MAX = 100;
  double a[MAX]; 
  int n; 
  public:
  double get(const int index = 0 ){
    if(index < n) return a[index];
    cout << "Error: get myArray element"
      << endl;
    return 0;
  }
  void set(const int index,
           const double value){
    if(index < n) 
      a[index] = value;
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
    cout << "copy constructor" << endl;
    n = b.n;
    for(int i = 0; i < n; i++) 
      a[i] = b.a[i];
  }
  ~myArray(){cout << "Destructor" << endl;}
  void print(void){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = "
        << a[i] << endl;
  }
  friend void f2(myArray k);
};
void f1(void); 
void f2(myArray); // declaration
int main(){f1();}
void f1(void){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x)/sizeof(double));
  myArray p(d);
  cout << "before call f2" << endl;
  f2(p);
}
void f2(myArray k){
  k.print(); 
  cout << k.n << endl;
}