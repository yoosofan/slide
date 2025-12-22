#include <iostream>
#include <cmath>
using namespace std;
class complexCls{
  double r, i;
 public:
  complexCls(int m = 0, int n = 0)
  {r = m; i = n;}
  void Show()
  {cout << r << "+ i " << i << endl;}
  double Magnitude()
  {return sqrt(r * r + i * i);}
  void input(){
    cout << "Enter real:"; cin >> r;
    cout << "Enter imaginary:"; cin >> i;
  }
  complexCls operator+(
      const complexCls& b){
    complexCls c;
    c.r = this->r + b.r;
    c.i = i + b.i;
    return c;
  }
  friend complexCls operator+(double x,
      const complexCls& b){
    complexCls c = b;
    c.r += x;
    cout << "in double+"<< endl;
    return c;
  }
  friend complexCls operator-(const complexCls& a,
      const complexCls& b){
    complexCls c;
    c.r = a.r - b.r;
    c.i = a.i - b.i;
    return c;
  }
 complexCls operator=(const complexCls& b){
    r = b.r;
    i = b.i;
    return *this;
  }
  double& operator[](int index){
    if(index < 0 || index > 1){
      cout << "index is out of range" 
        << index << endl; return r;
    }
    if(index) return i;
    return r;
  }
  friend bool operator==(
      const complexCls& a,
      const complexCls& b){
    return (a.r == b.r) && (a.i == b.i) ? 
      true: false;
  }
  friend bool operator!=(
      const complexCls& a,
      const complexCls& b)
  {return a == b ? false: true;}
  bool operator!()
  {return r == 0 && i == 0 ? true: false;}
  complexCls operator++()// ++a
  { i++; r++; return *this;}
  complexCls operator++(int dummy){//a++
    complexCls result=*this; 
    r++; i++; return result;
  }
  complexCls operator--() // --a
  { i--; r--; return *this;  }
  complexCls operator--(int dummy){//a--
    complexCls result=*this; 
    r--; i--; return result;
  }
  friend complexCls operator*(
      const complexCls& a,
      const complexCls& b){
    complexCls c;
    c.r = a.r * b.r - a.i * b.i;
    c.i = a.r * b.i + a.i * b.r;
    return c;
  }
};
void f1(){
  complexCls a(2, 3), b(2, 1), c(a);
  c = 2 + a;  c.Show();
  c = a++; // a.operator++(11);
  c.Show(); c = ++a;// a.operator++(); 
  c.Show();
  c = a--; c.Show(); c = --a; c.Show();
  if(a == b ) cout << "a == b" << endl;
  else cout << "a != b" << endl;
  if(!a) cout << "a is not zero" << endl;
}
int main(){f1();}/*
4+ i 3
2+ i 3
4+ i 5
4+ i 5
6+ i 7
a != b  */