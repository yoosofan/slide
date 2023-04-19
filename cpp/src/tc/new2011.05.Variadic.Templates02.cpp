#include<iostream>
using namespace std;
void printAll(){cout<<endl;}
template<typename T> void printAll(T m){cout<<m<<endl;}
template<typename T, typename... N>void printAll(T a, N... b){
  cout<<a<<'\t';
  printAll(b...);
}
int main(){  
  double x = 3, y = 7;  
  int a = 2, j = 34; 
  printAll(); 
  printAll(x); 
  printAll(a,x);  
  printAll(a,x,j,y);  
  string s1="hello", s2=":How are you?";
  printAll(s1,x,a,j,y,s2);
}
