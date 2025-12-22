//Error
#include<iostream>
using namespace std;
class complexCls{
  double re, im;
 public:
  complexCls(double a = 0, double b = 0){
    re = a;
    im = b;
  }
};
template<typename Type> class myArray{
  static const int MAX = 200;
  Type a[MAX];
  int n = 0;
public:
  void input(){
    cout<<"Enter n < " << MAX << " : ";
    do{cin >> n;} while(n<0 || n>MAX);
    for(auto i = 0; i < n; i++){
      cout << "Enter a[" << i << "]: ";
      cin >> a[i];
    }
  }
  void print(){
    cout << "n: " << n << endl;
    for(auto i = 0; i < n; i++)
      cout << a[i] << endl;
  }
};
int main(){
  myArray<int> m1, m2, m3;
  myArray<double> dm;
  myArray<char> cm;
  myArray<complexCls> ccm1;
  ccm1.input();
  m1.input();
  m1.print();
}
