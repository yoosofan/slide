#include <iostream>
using namespace std;
int f3(void);
int main(){
  int n = 10;
  n = f3();
  cout << "n: " << n << endl;
  return 0;
}
int f3(void){
  int n ;
  cout << "In F3: Enter n : " ;
  cin >> n;
  return n;
}
