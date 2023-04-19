#include <iostream>
using namespace std;
int f2(int n = 5, int z = 6);
int main(){
  int k = 5;
  cout << "k: " << k << "\t f2(" << k << "): " << f2(k) << endl;
  cout << "f2()" << f2() << endl;
  return 0;
}
int f2(int n, int z){
  cout << "n: "<< n << "\t z: " << z << endl;
  return n++;
}  
