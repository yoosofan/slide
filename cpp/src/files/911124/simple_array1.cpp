#include<iostream>
using namespace std;
struct myArray{
  double *a;
  int n;
 public:
  myArray(int n1=20,double k=0){cout<<"constructor is called\n";
    a = new double[n=n1];
    for(int i=0;i<n;i++) a[i]=k;
  }
  myArray(int n1, double *b){cout<<"second constructor is called\n";
    a = new double[n=n1];
    for(int i=0;i<n;i++) a[i]=b[i];
  }

  void print(void){cout<<endl;
    for(int i=0;i<n;i++)
      cout<<"A["<<i<<"]:"<<a[i];
  }
  ~myArray(){delete[] a; a=0; n=0;cout<<"destructor is called\n";}
};
void f1(){double t[]={3.4 , 5.6, 6,4};
  myArray a1(3,40),a2(3),a3,a4(3,t);
  //a1.init(30,4);a2.init(3);
  a1.print();a2.print();a4.print();
}
int main(){f1(); return 0;}
