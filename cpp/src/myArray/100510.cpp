#include <iostream>
using namespace std;
void f3(int &n);
void f2(int n);
int f4();
int main(){
  int n = 10;
  f3(n);
  cout << "n: " << n << endl;
  f2(n);
  cout << "n: " << n << endl;
  n = f4();
  cout << "n: " << n << endl;
}
void f3(int &n){ // Not good practice for this purpose
  cout << "In F3: Enter n : " ;
  cin >> n;
}
void f2(int n){
  cout << "In F2: Enter n : " ;
  cin >> n;
}
int f4(){
  int n;
  cout << "In F4: Enter n : " ;
  cin >> n;
  return n;
}
