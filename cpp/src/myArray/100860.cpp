#include <iostream>
using namespace std;
void print(double *pa);
void f1(void);
int main(){
  f1();
  auto s1 = "Hello";
  cout << string(typeid(s1).name()) << endl;
  if(typeid(string) == typeid(s1))
    cout << "strig" << endl;
  else if(typeid(char*) == typeid(s1))
    cout << "char*" << endl;
  else if(typeid(const char*) == typeid(s1))
    cout << "const char*" << endl; ///
  else
    cout << "other" << endl;
}
void print(double *pa){
  for(auto i = 0; i < 5; i++)
    cout << "pa[" << i << "]: " 
      << pa[i] << endl;
}
void f1(void){
  auto *px = new double[10];
  for(auto i = 0; i < 5 ; i++)
    px[i] = i+1;
  print(px);
}/*PKc
const char*
*/
