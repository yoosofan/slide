// Error
#include <iostream>
using namespace std;
int f3();
int main(){
  int n = 10;
  n = f3();
  cout << "n: " << n << endl;
}
int f3(){
  int n ;
  int& k = 12;
  cout << "In F3: Enter n : " ;
  cin >> n;
  return n;
}
