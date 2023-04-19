#include <iostream>
using namespace std;
class myArray{ // 100740
  static const int MAX = 100;
  double a[MAX];
  int n;
  public:
  double get(const int index = 0 ){
    if(index < n) return a[index];
    cout << "Error in getting an element of myArray" << endl;
    return 0;
  }
  void set(const int index, const double value){
    if( index < n ) a[index] = value;
    cout << "Error accessing myArray " << endl;
  }
  myArray(const double *ma = nullptr, int k = 0){
    if( k > MAX ) 
      k = MAX ;
    for(n = k--; k >= 0; k--)
      a[k] = ma[k];
  }
  void print(void){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = " << a[i] << endl;
  }
};
int main(){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x) / sizeof(double));
  d.set(30, 500);
  // d.n = 500; // So dangerous
  d.print();
}
