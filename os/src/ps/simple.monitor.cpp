#include<iostream>
using namespace std;
// simple monitor
monitor mp{
  // Shared data
  static const int n = 200;
  int buffer[n];
  int count;

  // Operations
  void f1(){/*....*/}
  void f2(){/*....*/}
  void f3(){/*....*/}
  void print(){
    for(int m1 : buffer)
      cout << m1 << ' ';
    cout << endl << n << endl;
  }

  // initialization code
  mp(){
    count = 0;
    for(int& m1 : buffer)
      m1 = -1;
  }
};
int main(){
  mp mp1;
  mp1.print();
}