#include<iostream>
using namespace std;
int search(double *a, double v, int n);
int search(string *a, string v, int n);
int main(){
  double ae[20] = {3, 4, 5, 6, 8, 9};
  cout << search(ae, 3, 6) << endl;
  cout << search(ae, 33, 6)  << endl;
  string am[]={"ali", "reza", "kamran", "hamid"};
  cout << search(am,"reza",4) << endl;
  return 0;
}
int search(double* a, double v, int n){
  for(int i = 0; i < n; i++) 
    if(a[i] == v) 
      return i;
  return -1;
}
int search(string* a, string v, int n){
  for(int i = 0; i < n; i++) 
    if(a[i] == v) 
      return i;
  return -1;
}
