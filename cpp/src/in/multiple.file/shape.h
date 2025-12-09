#pragma once
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