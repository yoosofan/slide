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
using namespace std;

class side{
  int d;
  public:
  side()=default;

  side(int a){
    if(a <= 0)
      throw "Side of a shape connot be negative or zero";
    d = a;
  }

  side(const side& a){
    int counter = 0;
    counter += 1; 
    this->d = a.d;
    cout << counter << "\tcopy constructor:" << d << endl;
  }
  void input(){
    cout<<"Enter length of side:"; cin>>d;
    while(d<=0){
      cout<<"Side must be >0"<<endl;
      cout<<"Enter length of side:"; cin>>d;
    }
  }
  side operator+(side a){
    side b(*this); // b(a)
    b.d+=a.d;
    return b;
  }
  bool operator >(side a){ return d >a.d;}

  void show(){cout<<d;}
};
class triangle{
  side a, b, c;

  bool check(){
    return a + b > c && a + c > b && b + c > a;
  }
public:

  triangle(side a, side b, side c){
	  this->a=a; 
	  this->b=b;
	  this->c=c;
	  if(!check())
		  throw "These sides do not generate a triangle: ";
  }

  void show(){
    cout <<"\t";a.show();
    cout <<",\t";b.show();
    cout <<",\t";c.show();
    cout <<endl;
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
	side a(3);
	side b(4),c(5);
	triangle t(a,b,c);
}

int main(){f2();}
