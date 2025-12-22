/*
 * Copyright 2018 Ahmad Yoosofan <yoosofan@myfastmail.com>,
 * http://yoosofan.github.io
 * http://yoosofan.kashanu.ac.ir
 * University of Kashan (http://kashanu.ac.ir)
 * 2014/05/03
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 2021/11/15 15:08:35
*/
#include <iostream>
#include <cmath>
using namespace std;
class side{
  int d = 1;
  public:
  side() = default;

  side(int a){
    if(a <= 0)
      throw "Side of a shape connot be negative or zero";
    d = a;
  }

  void input(){
    cout << "Enter length of side:";
    cin >> d;
    while(d <= 0){
      cout << "Side must be >0" << endl;
      cout << "Enter length of side:";
      cin >> d;
    }
  }

  side operator+(const side& a){
    side b(a);
    b.d += d;
    return b;
  }

  bool operator>(side a){ return d > a.d;}

  void show(){ cout << d; }
};

class triangle{
  side a, b, c;
  bool check(){
    return a + b > c && a + c>b && b + c > a;
  }
public:
  triangle(side a, side b, side c){
    this->a = a;
    this->b = b;
    this->c = c;
    if(!check())
      throw "These sides do notgenerate a triangle: ";
  }

  void show(){
    cout << "\t";
    a.show();
    cout << ",\t";
    b.show();
    cout << ",\t";
    c.show();
    cout << endl;
  }

  void input(){
    do{
      a.input();
      b.input();
      c.input();
    }while(!check());
  }
};

void f2(){
  side a(3), b(4), c(5);
  triangle t(a, b, c);
  t.show();
}
int main(){ f2(); }
