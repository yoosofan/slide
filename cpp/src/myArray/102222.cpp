#include <iostream>
using namespace std;
class myArray{// 102222.cpp
  double *a=nullptr; int n = 0;
  public:
  myArray(const double *ma=nullptr,
       int n = 0){int i;
    if(n == 0 || ma == nullptr)
    {n = 0; a = nullptr;}
    else{
      a = new double[this->n = n];
      for(i=0; i<n; i++)a[i]=ma[i];
    }
  }
  ~myArray(){delete[]a;a=nullptr;n=0;
    cout << "Destructor" << endl;
  }
  double get(const int index = 0 ){
    if(index < n) return a[index];
    cout<<"Error:get"<< endl;
    return 0;
  }
  void set(const int index,
           const double value){
    if( index < n)a[index]=value;
    else cout<<"Error:set"<<endl;
  }
  myArray(const myArray& b){int i;
    cout<<"copy constructor"<<endl;
    n = b.n; a = new double[n];
    for(i=0;i<n;i++)a[i]=b.a[i];
  }
};
int main(){const int MAX=100000;
  double x[MAX]={10,12,34,54};
  myArray d(x, MAX); myArray g,h;
}/*
in destructor
in destructor
in destructor */
