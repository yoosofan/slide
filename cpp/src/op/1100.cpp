#include <iostream>
#include <cmath>
using namespace std;
class complexCls{ 
  double r, i;
 public:
  complexCls(int m = 0, int n = 0)
  {r = m; i = n;}
  void Show(void)
  {cout << r << "+ i " << i << endl;}
  double Magnitude(void)
  {return sqrt(r * r + i * i);}
  void input(void){
    cout << "Enter real:"; cin >> r;
    cout << "Enter imaginary:"; cin >> i;
  }
  friend complexCls operator+(const complexCls& a,
      const complexCls& b){
    complexCls c;
    c.r = a.r + b.r;
    c.i = a.i + b.i;
    return c;
  }
  friend complexCls operator-(const complexCls& a,
      const complexCls& b){
    complexCls c;
    c.r = a.r - b.r;
    c.i = a.i - b.i;
    return c;
  }
  friend complexCls operator*(const complexCls& a,
      const complexCls& b){
    complexCls c;
    c.r = a.r * b.r - a.i * b.i;
    c.i = a.r * b.i + a.i * b.r;
    return c;
  }
 complexCls operator=(const complexCls& b){
    r = b.r;
    i = b.i;
    return *this;
  }
  double& operator[](int index){
    if(index < 0 || index > 1){
      cout << "index is out of range" << index << endl;
      return r;
    }
    if(index) return i;
    return r;
  }
  friend bool operator==(const complexCls& a,
      const complexCls& b)
  {return (a.r == b.r) && (a.i == b.i) ? true: false;}
  friend bool operator!=(const complexCls& a,
      const complexCls& b)
  {return a == b ? false: true;}
  bool operator!(void)
  {return r == 0 && i == 0 ? true: false;}
};
void f1(void){
  complexCls a(2, 3), b(2, 1), c(a);
  //c = 2 + a;  c.Show();
  c = a - 2;  c.Show();
  if(a == b ) cout << "a == b" << endl;
  else cout << "a != b" << endl;
  if(!a) cout << "a is not zero" << endl;
}
int main(){f1();}/*
0+ i 3
a != b */