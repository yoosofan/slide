#include <iostream> 
using namespace std; // 100488.02.this.cpp
struct myArray{
  static const int MAX = 100;
  static int other_static;
  double a[MAX];
  int n;  // myArray* this = & ....
  myArray(const double a[], int n){
    if( n > MAX) 
      n = MAX ;
    for(this -> n = n--; n >= 0; n--)
      this - > a[n] = a[n];
  }
  void print(void){
    cout << " n = " << this->n << "\t other_static: " 
      << other_static << endl;
    for(int i = 0; i < (*this).n; i++)
      cout << "a[" << i << "] = " << this->a[i] << endl;
  }
  static void printStatic(void){
    cout << "MAX: " << MAX << endl;
    cout << "other_static: " << other_static << endl;
  }
};
int myArray::other_static = 20 ;
int main(){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x) / sizeof(double));
  myArray b(x, sizeof(x) / sizeof(double));
  b.printStatic();
  d.print();  b.a[1] = 94; b.other_static = 94; 
  d.print();  b.print(); myArray::printStatic();
}
