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
 * 2021/11/15 15:08:25
 * 2022/05/07 16:39:47
*/
#include <iostream>
using namespace std;
class side{
  int d = 1;
  public:
  // side(){};
  side(int a=1){
    if(a <= 0)
      throw "Side of a shape connot be negative or zero";
    d = a;
  }

  void input(){
    cout << "Enter length of side:";
    cin >> d;
    while(d <= 0){
      cout << "Side must be >0"<<endl;
      cout << "Enter length of side:";
      cin >> d;
    }
  }

  side operator+(const side& a){// add
    side b(*this); // b(a)
    // side b; b.d = d + a.d;
    b.d += a.d;
    return b;
  }

  bool operator >(side a){// bool:true, false
    return d > a.d;
  }

  void show(){cout<<d;}
};

class triangle{
  side a, b, c;
  // (a.operator+(b)).operator>(c)

  bool check(){
    return (a + b > c && a + c > b && b + c > a );
  }// true, false
  public:

    triangle(side a, side b, side c){
    this->a = a;
    this->b = b;
    this->c = c;
    if(!check())
      throw "These sides do not generate a triangle: ";
  }

  void show(){
    cout << "\t";  a.show();
    cout << ",\t"; b.show();
    cout << ",\t"; c.show();
    cout << endl;
  }
  void input(){
    //int k;
    do{
      a.input();
      b.input();
      c.input();
    }while(!check());
  }
};
void f2(){
  side a(3), b(4), c(5), d;
  d = a + b; // d = a.operator+(b);
  d.show(); cout << endl;
  if(a > b) // a.operator>(b)
    cout << "a > b" << endl;
  else
    cout << "b >= a" << endl;
  triangle t(a, b, c);
  t.show();
}
int main(){f2();}
