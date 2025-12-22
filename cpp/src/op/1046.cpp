#include <iostream>
#include <cmath>
using namespace std;
class complexCls{
  double r,i; // Error
 public:
  complexCls(int m = 0, int n = 0)
  {r = m; i = n;}
  void Show() const
  {cout << r << "+ i " << i << endl;}
  double Magnitude() const
  {return sqrt(r * r + i * i);}
  void input(){
    cout << "Enter real:"; cin >> r;
    cout << "Enter imaginary:";
    cin >> i;
  }
  complexCls operator+(complexCls& b){
    complexCls c;
    c.r = r + b.r;
    c.i = this->i + b.i;
    return c;
  }
  friend complexCls add(const complexCls& a,
      const complexCls& b){
    complexCls c = a;
    c.r += b.r;
    c.i += b.i;
    return c;
  }
};
void f1(){
  complexCls a(2, 3), b(2, 1), c(a);
  c = a + 2;
  c.Show();
  c = add(a,b);
  c.Show();
}
int main(){f1();}