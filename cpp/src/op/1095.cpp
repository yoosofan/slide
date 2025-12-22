#include <iostream>
#include <cmath>
using namespace std;
class complexCls{
  double r, i;
 public:
  void Show() const
  {cout << r << "+ i " << i << endl;}
  double Magnitude() const
  {return sqrt(r * r + i * i);}
  void input(){
    cout << "Enter real:"; cin >> r;
    cout << "Enter imaginary:"; cin >> i;
  }
  complexCls operator-(const complexCls& b){
    complexCls c;
    c.r = r - b.r;
    c.i = this->i - b.i;
    return c;
  }
  complexCls operator*(const complexCls& b){
    complexCls c;
    c.r = r * b.r - i * b.i;
    c.i = r * b.i + i * b.r;
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
  complexCls operator+(const complexCls& b){
    complexCls c;
    c.r = r + b.r;
    c.i = this->i + b.i;
    return c;
  }
  complexCls(int m = 0, int n = 0)
  {r = m; i = n;}
};
void f1(){
  complexCls a(2, 3), b(2, 1), c(a);
  c = complexCls(2) + a;  c.Show();
  // c.operator=(2.operator+(a));
  c = a - 2;  c.Show();
  // c.operator=(a.operator+(2));
  c[0] = 56;
  c.Show();
}
int main(){f1();}