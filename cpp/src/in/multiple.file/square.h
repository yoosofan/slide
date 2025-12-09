#pragma once
#include<iostream>
#include "shape.h"
#include "rectangle.h"
using namespace std;
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

