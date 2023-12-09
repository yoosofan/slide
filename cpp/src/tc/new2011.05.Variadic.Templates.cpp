#include<iostream>
using namespace std;
void printAll();
template<typename T, typename... N>
void printAll(T a, N... b);
int main(){
  double x = 3, y = 7;  int a = 2, j = 34;
  printAll(); 
  printAll(x); 
  printAll(a, x);
  printAll(a, x, j, y);
  string s1 = "hello", s2 = ":How are you?";
  printAll(s1, x, a, j, y, s2);
}
void printAll(){cout << endl;}
template<typename T, typename... N>
void printAll(T a, N... b){
  cout << a << '\t';
  printAll(b...);
}
/*
void printAll(double a){ // Line 9
  cout << a << '\t';
  printAll();
}

void printAll(int a, double a1){ // Line 10
  cout << a << '\t';
  printAll(a1); // line 22
}

void printAll(int a, double a1, int a2, double a3){ // Line 11
  cout << a << '\t';
  printAll(a1, a2, a3);
}
void printAll(double a, int a2, double a3){ // Line 11 continue
  cout << a << '\t';
  printAll(a2, a3); // Line 27
}

//   printAll(s1, x, a, j, y, s2);
void printAll(string a, double a1, int a2, int a3, double a4, string a5){ // Line 12
  cout << a << '\t';
  printAll(a1, a2, a3, a4, a5);
}
void printAll(double a, int a2, int a3, double a4, string a5){ // Line 12 continue 1
  cout << a << '\t';
  printAll(a2, a3, a4, a5);
}
void printAll(int a, int a3, double a4, string a5){ // Line 12 continue 2
  cout << a << '\t';
  printAll(a3, a4, a5);
}
void printAll(int a, double a4, string a5){ // Line 12 continue 3
  cout << a << '\t';
  printAll(a4, a5);
}
void printAll(double a, string a5){ // Line 12 continue 4
  cout << a << '\t';
  printAll(a5);
}
void printAll(string a){ // Line 12 continue 5
  cout << a << '\t';
  printAll();
}
*/