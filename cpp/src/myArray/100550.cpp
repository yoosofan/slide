#include <iostream>
using namespace std;
int f2(int n , int z = 6);
int main(){
  int k = 5, n;
  cout << "f2(k, 8) " << endl;
  n = f2(k, 8);
  cout << "n: " << n << endl;
  cout << "f2(" << k << "): ";
  n = f2(k-2);
  cout << "n: " << n << endl;
  return 0;
}
int f2(int n, int z){
  cout << "n: "<< n << "\t z: " << z << endl;
  return n++;
}  
