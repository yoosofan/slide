#include <iostream>
using namespace std;
const int MAX_NUMBER_OF_CELLS = 100;
struct myArray{
  double a[MAX_NUMBER_OF_CELLS];
  int n;
  myArray(double ma[], int k){
    if( k > MAX_NUMBER_OF_CELLS )
      k = MAX_NUMBER_OF_CELLS ;
    for(n = k--; k >= 0; k--)
      a[k] = ma[k];
  }
  void print(){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = " << a[i] << endl;
  }
};
int main(){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x) / sizeof(double));
  d.print();
}
