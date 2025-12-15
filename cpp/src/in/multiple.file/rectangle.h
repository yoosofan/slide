#pragma once
#include<iostream>
#include "shape.h"
using namespace std;
//struct Square;
class Rectangle: public Shape{
  int h=1,w=1;public:
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
  friend void Square::print();
};
