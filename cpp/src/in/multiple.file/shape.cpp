#pragma once
#include<iostream>
#include "shape.h"
using namespace std;
virtual void Rectangle::print(){
  Shape::print();
  cout<<"w: "<< w <<
    "\th: "<< w << endl;
}
virtual double Rectangle::Area()
{return h*w;}
virtual void Square::print(){
    Shape::print();
    cout << "d: " <<w<<endl;
}
