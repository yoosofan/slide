#include<iostream>
using namespace std;
void swap(double&, double&);
void swap(string&, string&);
int main(){
  int i = 1, j = 2, k = 3;
  double x = 1, y = 2 , z = 3;
  swap(x, y);
  cout << "x= " << x << "\ty= " << y << endl;
  string s1 = "Salam";
  string s2 = "Goodbye";
  swap(s1, s2);
  cout << "s1= " << s1 << "\ts2= " << s2 << endl;
}
void swap(double& a, double& b){
  double temp = a;
  a = b;
  b = temp;
}
void swap(string& a, string& b){
  string temp = a;
  a = b;
  b = temp;
}
