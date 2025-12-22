#include <iostream>
using namespace std;
struct myArray{//100423.33.cpp
  int n = 0;
  double a[100];
  void set(double ma[], int k){
    n = k;
    for(int i = 0; i < n; i++)
      a[i] = ma[i];
  }
  void print(){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = "
        << a[i] << endl;
  }
};
int main(){
  double x[2000]{10, 12, 34, 54};
  myArray d;
  d.set(x, 2000);
  d.print();
  myArray ax[30000];
  for(int i=0 ; i<30000; i++){
    ax[i].set(x, 2000);
    ax[i].print();
  }
}

/* ./a.out
Segmentation fault (core dumped)
*/

