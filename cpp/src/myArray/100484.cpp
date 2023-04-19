#include <iostream> // Error
using namespace std; // 100484
struct myArray{
  static const int MAX = 100;
  static int other_static = 20;
  double a[MAX];
  int n;
  myArray(const double ma[], int k){
    if( k > MAX) 
      k = MAX ;
    for(n = k--; k >= 0; k--)
      a[k] = ma[k];
  }
  void print(void){
    cout << " n = " << n 
      << "\t other_static: " 
      << other_static << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = " 
      << a[i] << endl;
  }
};
// int myArray::other_static = 20 ;
// int myArray.other_static = 20 ;
int main(){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x) / sizeof(double));
  myArray b(x, sizeof(x) / sizeof(double));
  d.print();  b.a[1] = 94;  
  b.other_static = 94; d.print();  b.print();
}
