#include<iostream>
using namespace std;
template<typename T>int search(
    T *a, T v, int n){
  for(int i = 0; i < n; i++) 
    if(a[i] == v) 
      return i;
  return -1;
}
template<typename T>void mySwap(
    T& a, T& b){
  T t = a;
  a = b;
  b = t;
}
int main(){ 
  double ae[20]{5, 6, 4, 2, 1};
  string ms[] = {"aa", "bb", "cc"};
  cout << search<double>(ae, 4, 5)
    << endl;
  cout << search<double>(ae, 33, 5) 
    << endl;  
  cout << search<string>(ms, "bb", 3)
    << endl;
  int i = 1, j = 2;
  mySwap<int>(i, j);   
  cout << "i= " << i << "\tj= " 
    << j << endl;
  string s1 = "aa", s2 = "bb";
  mySwap<string>(s1, s2);
  cout << "s1: " << s1 << "\ts2: "
    << s2 << endl;
}
