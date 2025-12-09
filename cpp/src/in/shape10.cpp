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
    cout<<"r: "<< r << endl;
  }
  virtual double Area()
  {return r*r*3.14;}
};
class Rectangle: public Shape{
  int h=1,w=1; public:
  Rectangle(int h1=1,int w1=1,
    string name="Rectangle",
    string color="Black"):
      Shape(name, color)
  {h=h1;w=w1;}
  virtual void print(){
    Shape::print();
    cout<<"w: "<< w
      "\th: "<< w << endl;
  }
  virtual double Area()
  {return h*w;}
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
void f1(Shape* p){
  cout<<p->Area()<<endl;
  p->print();
}
int main(){
  Square sq(3);
  Circle c1(5);
  f1(&sq); f1(&c1);
}