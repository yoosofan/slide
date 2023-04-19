#include<iostream>
using namespace std;
class A{};
class Shape: public A{
protected:
  string name = "shape";
  string color = "shape";
  int test = 2;
public:
  int Area(void){return 0;}
  int testValue(void){return test;}
  Shape() = default;
  friend ostream& operator <<(ostream& o1, const Shape& s1){
    o1 << "name: " << s1.name << "\tcolor: " << s1.color;
    return o1;
  }
};
class Square: public Shape{
  int d = 1;
public:
  int Area(void){return d*d;}
  Square(int d){this->d=d; test = 4;}
  int testValue(void){return test;}
  Square() = default;
  friend ostream& operator <<(ostream& o1, const Square& s1){
    o1 << Shape(s1) << "\tside: " << s1.d;
    return o1;
  }
};
int main(){
  Shape s;
  cout << s.Area() << endl;
  cout << "test in Shape: "
    << s.testValue() << endl;
  // cout << s.test << endl; // Error
  Square sq(3);
  cout << sq.Area() << endl;
  Shape* ps = &s;
  cout << ps->Area() << endl;
  ps = &sq;
  cout << ps->Area() <<endl;
  cout << "test value: "
    << sq.testValue() << endl;
  A *pa;
  return 0;
}
