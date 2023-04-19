#include <iostream>// istream
#include <cmath>
using namespace std;
class complexCls{//1130
  double r, i;
 public:
  complexCls(int m = 0, int n = 0):r(m), i(n){}
  friend ostream& operator<<(ostream& o1, 
      const complexCls& a){
    o1 << a.r << "+i" << a.i;
    return o1;
  }
  friend istream& operator>>(istream& i1,
      complexCls& a){
    cout << "Enter real:"; i1 >> a.r;
    cout << "Enter imaginary:"; i1 >> a.i;
    return i1;
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
  complexCls operator++(void)   // ++a
  { i++; r++; return *this;  }
  complexCls operator++(int dummy) // a++
  {complexCls result=*this; r++; i++; return result;}
  complexCls operator--(void)   // --a
  { i--; r--; return *this;  }
  complexCls operator--(int dummy) // a--
  {complexCls result=*this; r--; i--; return result;}
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
      cout << "index is out of range" 
        << index << endl; return r;
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
  c = 2 + a;  cout << c << endl;
  cin >> c; cout << c << endl;
}
int main(){f1();}/*
4+i3
Enter real:2
Enter imaginary:4
2+i4 */