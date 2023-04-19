#include <iostream>
using namespace std;
class myArray{ // Error
  static const int MAX = 100;
  double a[MAX];
  int n;
  public:
  double get(const int index = 0 ){
    if(index < n) return a[index];
    cout << "Error in myArray" << endl;
    return 0;
  }
  void set(const int index,
           const double value){
    if( index < n ) a[index] = value;
    else
      cout << "Error accessing myArray "
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
  }
  ~myArray(){
    cout << "Destructor" << endl;
  }
  void print(void){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = " 
           << a[i] << endl;
  }
};
int main(){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x)/sizeof(x[0]));
  myArray p(d);
  // myArray p = d;
}/*
copy construcotr
Destructor
Destructor
*/
