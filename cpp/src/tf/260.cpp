#include<iostream>
using namespace std;
template<typename T> int search(T* a, T v, int n){
  for(auto i=0; i < n; i++) 
    if(a[i]==v) 
      return i;
  return -1;
}
void f1(void); //~ void f2(void);
int main(){
  f1();
  f2();
  return 0;
}
void f1(){
  double ae[20] = {3,4,5,6,8,9};
  // double* p; cout << sizeof(p) << endl;
  string am[]={"ali", "reza", "kamran", "hamid"};
  int nae = sizeof(ae) / sizeof(ae[0]);
  int nam = sizeof(am) / sizeof(am[0]);
  cout << search<double>(ae, 3, nae) << endl;
  cout << search<double>(ae, 33, nae) << endl;
  cout << search<string>(am,"reza", nam) <<endl;
} /*
void f2(){
  double ae[20] = {3,4,5,6,8,9};
  // double* p; cout << sizeof(p) << endl;
  string am[]={"ali", "reza", "kamran", "hamid"};
  int nae = sizeof(ae) / sizeof(ae[0]);
  int nam = sizeof(am) / sizeof(am[0]);
  cout << search(ae, 3, nae) << endl;
  cout << search(ae, 33, nae) << endl;
  cout << search(am,"reza", nam) <<endl;
}
*/
