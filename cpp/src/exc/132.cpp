#include <iostream>
using namespace std;
void f1(int i){
  if(i <= 0)  throw 2;
  cout << "f1: " << i << endl;
}
void f2(int mm){
  if(mm > 20)  throw 3;
  cout << "f2: " << mm << endl;
}
void f4(int mm){
  if(mm < 10)  throw 5;
  cout << "In f4 mm " << mm << endl;
}
int f3(void){ int x = 3;
  f1(3); x++; cout << "f3: " << x << endl;
  f4(-22); x++; cout << "f3: " << x << endl;
  return x;
}
void f8(void){
  try{
    f1(1);
    f2(12);
    cout << f3() << endl;
    f2(13);
  }catch(const int& m1)
  {cout << "In main " << m1 << endl;}
  cout<< "End" << endl;
}
int main(){f8();}
