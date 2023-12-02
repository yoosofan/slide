#include<iostream>
using namespace std;
void mySwap(double&, double&);
void mySwap(string&, string&);
int main(){
  int i = 1, j = 2, k = 3;
  double x = 1, y = 2 , z = 3;
  MySwap(x, y);
  cout << "x= " << x << "\ty= " << y << endl;
  string s1 = "Salam";
  string s2 = "Goodbye";
  mySwap(s1, s2);
  cout << "s1= " << s1 << "\ts2= " 
       << s2 << endl;
}
void mySwap(double& a, double& b){
  double temp = a;
  a = b;
  b = temp;
}
void mySwap(string& a, string& b){
  string temp = a;
  a = b;
  b = temp;
}
