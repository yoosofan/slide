#include <iostream>
using namespace std;
void f2(void);
int main(){
  f2();
  return 0;
}
void f2(void){
  int n = 5;
  int &rn = n;
  cout << "n : "<< n << "\t rn : " << rn << endl;
  rn = 8;
  cout << "n : "<< n << "\t rn : " << rn << endl;
  n = 16;
  cout << "n : "<< n << "\t rn : " << rn << endl;
  int m = 4;
  rn = m;
  cout << "n : "<< n << "\t rn : " << rn << endl;
  m = 8;
  cout << "n : "<< n << "\t rn : " << rn << endl;
  int &rk = n;
  cout << "n : "<< n << "\t rn : " << rn << endl;
  rk = 8;
  cout << "n : "<< n << "\t rn : " << rn << endl;

}  
