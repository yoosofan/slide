#include <iostream>
using namespace std;
class myArray{  // 102222.cpp
  double *a = nullptr;
  int n = 0;
  public:
  myArray(const double *ma = nullptr,
       int n = 0){
    if(n == 0 || ma == nullptr){
      n = 0;
      a = nullptr;
    }
    else{
      a = new double[this->n = n];
      for(int i=0; i<n; i++)
        a[i] = ma[i];
    }
  }
  ~myArray(){
    delete[] a;
    a = nullptr;
    n = 0;
    cout << "in destructor" << endl;
  }
  double get(const int index = 0 ){
    if(index < n) return a[index];
    cout<<"Error: get myArray element"
      << endl;
    return 0;
  }
  void set(const int index,
           const double value){
    if( index < n ) a[index] = value;
    else
      cout<<"Error set myArray element"
          << endl;
  }
  myArray(const myArray& b){
    cout << "copy constructor" << endl;
    n = b.n;
    a = new double[n];
    for(int i = 0; i < n; i++)
      a[i] = b.a[i];
  }
};
int main(){
  double x[100000]={10,12,34,54};
  myArray d(x,sizeof(x)/sizeof(double));
  myArray g,h;
}/*
in destructor
in destructor
in destructor */