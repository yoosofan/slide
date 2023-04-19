// Error
#include <iostream>
using namespace std;
class myArray{//myarray/102050.cpp
  static const int MAX = 100;
  double a[MAX];
  int n = 0;
  public:
  double get(const int index = 0 ){
    if(index < n) return a[index];
    cout << "Error in getting" << endl;
    return 0;
  }
  void set(const int index, 
          const double value){
    if( index < n ) 
      a[index] = value;
    cout << "Error accessing myArray " 
         << endl;
  }
  myArray() = default;
  myArray(const double* ma, int k){
    if( k > MAX ) 
      k = MAX ;
    for(n = k--; k >= 0; k--)
      a[k] = ma[k];
  }
  explicit myArray(double x){
    n = 1;
    a[0] = x;
  }
  myArray add(myArray b){
    myArray t = b;
    int i;
    for(i=0; i<t.n && i<n; i++)
      t.a[i]+=a[i];
    if(i<n)
      for(;i<n;i++)
        t.a[i] = a[i];
    t.n=i;
    return t;
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
  myArray d(x, sizeof(x)/sizeof(double));
  myArray k(2), r=3;
  myArray p = d.add(2);//p=d+2;
  p.print(); k.print();
}
