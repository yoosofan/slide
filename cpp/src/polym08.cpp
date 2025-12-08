#include<iostream>
using namespace std;
class Shape{protected://abstract
  string name, color; public:
  Shape(string name="shape",
    string color="white"):
      name(name),color(color)
  {}
  virtual double Area() = 0;//abstract
  virtual void print(){
    cout << "name: " << name
      << endl << "color: "
      << color << endl;
  }
};
class Circle: public Shape{
  int r; public:
  Circle(int d=1,
    string name="Circle",
    string color="White"):
      Shape(name, color)
  {r=d;}
  virtual void print(){
    Shape::print();
    cout <<  "r: " << r << endl;
  }
  virtual double Area()
  {return r*r*3.14;}
};
class Square: public Shape{
  int d; public:
  virtual double Area()
  {return d*d;}
  Square(int d=1,
    string name="square",
    string color="blue"):
      Shape(name, color)
  {this->d=d;}
  virtual void print(){
      Shape::print();
      cout << "d: " <<
        this->d << endl;
  }
};
void f2(Square p)
{cout<<p.Area()<<endl;}
void f1(Shape* p)
{cout<<p->Area()<<endl;
  p->print() ;
}
int main(){
  Square sq(3);
  Circle c1(5);
  f2(sq); f1(&sq);
  f1(&c1);
}