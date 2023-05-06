#include<iostream>
using namespace std;
class A{};
class Shape: public A{
protected:
  string name;
  string color;
public:
  int Area(void){return 0;}
};
class Square: public Shape{
  int d;
public:
  int Area(void){return d*d;}
  Square(int d=1){this->d=d;}
};
void f1(Shape a)
{cout << a.Area() << endl;}
int main(){
  Shape s;
  f1(s);
  Square sq(3);
  cout << sq.Area() << endl;
  Shape* ps = &s;
  cout << ps->Area() << endl;
  ps = &sq;
  cout << ps->Area() << endl;
}
