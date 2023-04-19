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
  complexCls operator+(const complexCls& b){
    complexCls c;
    c.r = r + b.r;
    c.i = this->i + b.i;
    return c;
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
};
void f1(void){
  complexCls a(2, 3), b(2, 1), c(a);
  c = a + 2;  c.Show();
  c = a - 2;  c.Show();
}
int main(){f1();}