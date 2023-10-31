#include <iostream>
using namespace std;
int f2(int n = 5);
int main(){
  int k = 5;
  cout << "k: " << k << "\t f2(" << k << "): " << f2(k) << endl;
  cout << "f2()" << f2() << endl;
}
int f2(int n){
  cout << "n : "<< n << endl;
  return n++;
}  
