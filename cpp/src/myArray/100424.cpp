#include <iostream> //MyArray/100424
using namespace std;
const int MAX_NUMBER_OF_CELLS = 100;
struct myArray{
  double a[MAX_NUMBER_OF_CELLS];
  int n = 0;
  void set(double ma[], int k){
    if(k >= 0 && k < MAX_NUMBER_OF_CELLS){
      n = k;
      for(int i = 0; i < n; i++)
        a[i] = ma[i];
    }
    else
      cout << "Number of Elements is wrong" 
        << k << endl;    
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
  myArray d;
  d.set(x, sizeof(x) / sizeof(x[0]));
  d.print();
}
