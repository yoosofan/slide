#include <iostream> 
using namespace std;
struct myArray{//100488.01.this
  static const int MAX = 100;
  static int other_static;
  double a[MAX];
  int n; // myArray* this = & ....
  myArray(const double ma[], int k){
    if( k > MAX) k = MAX ;
    for(n = k--; k >= 0; k--)
      a[k] = ma[k];
  }
  void print(){
    cout << "n= " << n << "\t other " 
      << other_static << endl;
    for(int i = 0; i < n; i++)
      cout << a[i] << endl;
  }
  static void printStatic(){
    cout << "MAX: " << MAX << 
    "\tother: "<<other_static<<endl;
  }
};
int myArray::other_static = 20 ;
int main(){double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x)/sizeof(double));
  // d.this = &d;
  myArray b(x, sizeof(x)/sizeof(double));
  b.printStatic(); d.print();b.a[1] = 94; 
  b.other_static = 94;  d.print();  
  b.print(); myArray::printStatic();
}
