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
  protected: int h=1,w=1;public:
  Rectangle(int h1=1,int w1=1,
    string name="Rectangle",
    string color="Black"):
      Shape(name, color)
  {h=h1;w=w1;}
  virtual void print(){
    Shape::print();
    cout<<"w: "<< w <<
      "\th: "<< w << endl;
  }
  virtual double Area()
  {return h*w;}
};
struct Square: public Rectangle{
  Square(int d=1,
    string name="Square",
    string color="Blue"):
    Rectangle(d, d, name, color)
  {}
  virtual void print(){
      Shape::print();
      cout << "d: " <<w<<endl;
  }
};
int main(){
  Shape* p1[3];
  p1[0] = new Circle(4);
  p1[1] = new Rectangle(3,5);
  p1[2] = new Square(6);
  for(int i=0; i< 3; i++){
    cout << p1[i]-> Area() << endl;
    p1[i] -> print() ;
  }
}