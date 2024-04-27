#include <iostream>
using namespace std;
void f1(int i){
  if(i <= 0)
    throw 2;
  cout << "f1: " << i << endl;
}
void f2(int mm){
  if(mm > 20) throw 3;
  cout << "f2: " << mm << endl;
}
void f4(int mm){
  if(mm < 10)  throw 5;
  cout << "In f4 mm " << mm << endl;
}
int f3(int x = 34){
  f1(3); x++ ; cout << "f3: " << x << endl;
  f4(x); x++ ; cout << "f3: " << x << endl;
  return x;
}
void f5(void){
  cout << "start of F5" << endl;
  f3(3);
  cout << "End of F5" << endl;
}
void f8(void){
  try{
    cout << f3() << endl;
    f5();
    f2(13);
  }catch(const int& m1)
  {cout << "In main " << m1 << endl;}
  cout<< "End" << endl;
}
int main(){f8();}
