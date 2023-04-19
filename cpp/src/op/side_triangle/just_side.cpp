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
 * 2022/05/07 16:39:47
*/
#include <iostream>
#include <cmath>
using namespace std;
class side{
  unsigned d;
public:

  side() = default;

  side(int a){
    if(a <= 0)
      throw "Side of a shape connot be negative or zero";
    d = a;
  }

  side(const side& a){
    static int counter = 0;
    counter += 1;
    this->d = a.d;
    cout << counter << "\tcopy constructor:" << d << endl;
  }

  void input(void){
    cout << "Enter length of side:";
    cin >> d;
    while(d <= 0){
      cout << "Side must be >0" << endl;
      cout << "Enter length of side:";
      cin >> d;
    }
  }

  side operator+(const side& a){
    side b; //side b(*this); // b(a)
    b.d = this->d + a.d;
    return b;
  }

  bool operator >(const side &a){
    cout << d << " > " << a.d << endl;
    return  d > a.d;
  }

  friend ostream& operator<<(ostream& o1, side& a1){
    o1 << a1.d << endl;
    return o1;
  }

  friend istream& operator >>(istream& i1, side& a1){
    cin >> a1.d;
    if( a1.d <= 0)
      throw "side must be greater than zero";
    return i1;
  }
};

void f3(void){
  side s1(1);
  cout << "Enter side ";
  cin >> s1;
  cout << s1;
}

int main(){f3();}
