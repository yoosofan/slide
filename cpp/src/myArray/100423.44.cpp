#include <iostream> //MyArray/100423.44
using namespace std;
struct myArray{
  void set(double ma[], int k){
    if(k >= 0 && k < 100)
      for(n = k--; k >= 0; k--)
        a[k] = ma[k];
    else
      cout << "Number of Elements is wrong"
        << k << endl;
  }
  void print(){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = "
        << a[i] << endl;
  }

  double a[100];
  int n = 0;
};
int main(){
  double x[]{10, 12, 34, 54};
  myArray d;
  d.set(x, sizeof(x) / sizeof(x[0]));
  d.print();
}
