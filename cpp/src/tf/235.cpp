#include<iostream>
using namespace std;
template<typename T>int search(
    T* a, T v, int n){
  for(int i=0; i<n; i++) 
    if(a[i] == v) 
      return i;
  return -1;
}
template<typename T>void mySwap(
    T& a,T& b){
  T t = a;
  a = b;
  b = t;
}
template<typename T> void mySort(
    T* a, int n){
  int i,j; 
  T temp;
  for(i=0;i<n;i++)
    for(j = i+1; j < n; j++)
      if(a[i] > a[j]){
        temp = a[i]; 
        a[i] = a[j]; 
        a[j] = temp;
      }
}
int main(){ 
  double ae[]{5, 6, 4, 2, 1}; 
  int i = 1, j = 2;
  for(double& m1 : ae)
    cout << m1 << '\t' ;
  cout << endl;
  mySort<double>(ae, 5); 
  for(double& m1 : ae) 
    cout << m1 << '\t';  
  cout<<endl;
  string s1[]{"aa", "dd", "cc"};
  for(string& st1: s1)
    cout << st1 << '\t';
  cout << endl;
  mySort(s1, 3);
  for(string& st1: s1)
    cout << st1 << '\t';
  cout << endl;
}
