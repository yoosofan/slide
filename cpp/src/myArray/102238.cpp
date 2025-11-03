#include <iostream>
using namespace std;
class myArray{int n=0;//102238.cpp
  double *a=nullptr; public:
  myArray(const double *ma=nullptr,
      int n = 0){// Error
    if(n == 0 || ma == nullptr)
    {n = 0; a = nullptr;}
    else{a=new double[this->n=n];
      for(int i=0;i<n;i++)a[i]=ma[i];
    }
  }
  double get(const int index = 0 ){
    if(index < n) return a[index];
    cout<<"Error:get"<<endl;
    return 0;
  }
  void set(const int index,
           const double value){
    if(index<n) a[index] = value;
    else cout<<"Error:set"<<endl;
  }
  void print(){
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << a[i] << endl;
  }
};
void f2(myArray);
int main(){double x[]={10,12,34,54};
  myArray d(x, 4);  myArray p(d);
  cout<<"before f2"<<endl;  f2(p);
}
void f2(myArray k){k.print();}/*
copy constructor
before call f2
copy constructor
 n = 4
a[0] = 10
a[1] = 12
a[2] = 34
a[3] = 54
in destructor
in destructor
in destructor*/
