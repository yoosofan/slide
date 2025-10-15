#include <iostream>
using namespace std;
void f2();void print();
int main(){f2();}
void f2(){int n = 5;
  int &rn = n;
  rn = 8; print(n, rn)
  n = 16; print(n, rn)
  int m = 4; print(n, rn)
  rn = m; print(n, rn)
  m = 8; print(n, rn)
  int &rk = n; print(n, rn)
  rk = 8;  print(n, rn);
}  
void print(int n, int& rn){
  cout << "n: "<< n << "\trn: " 
    << rn << endl;
}
