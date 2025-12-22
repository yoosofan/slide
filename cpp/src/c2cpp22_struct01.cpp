#include <iostream>
using namespace std;

struct firstStruct{  };
struct secondStruct{ };
struct thirdStruct{ };
firstStruct f1();
void f2(firstStruct);
int main(){
  firstStruct myfs;
  myfs = f1();
  f2(myfs);
}
firstStruct f1(){
  firstStruct fs1;
  secondStruct ss1;
  thirdStruct ts1;
  return fs1;
}
void f2(firstStruct m1){
  cout << &m1 ;
  cout << "\n";
}
