/*
 * Copyright 2018 Ahmad Yoosofan <yoosofan@myfastmail.com>,
 * http://yoosofan.github.io;
 * http://yoosofan.kashanu.ac.ir
 * University of Kashan (http://kashanu.ac.ir)
 * 2014/05/03
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
*/
#include <iostream>
#include <cmath>
using namespace std;
struct side{ int d;
  side(int a = 1){
    if(a<=0){cout<<"Side of a shape connot be negative or zero"<<endl;exit(0);}
    d=a;
  }
  side(const side&a){d = a.d;cout<<"copy constructor:"<<d<<endl;}
  void input(){
    cout<<"Enter length of side:"; cin>>d;
    while(d<=0){
      cout<<"Side must be >0"<<endl;
      cout<<"Enter length of side:"; cin>>d;
    }
  }
  void print(){cout << d;}
};
class triangle{
  side a, b, c;
  bool check(){return (a.d+b.d>c.d && a.d+c.d>b.d && b.d+c.d>a.d);}// true, false
  public:
  triangle(const side& a, const side& b, const side& c){
      this->a=a;
      this->b=b;
      this->c=c;
      if(!check()){
	    cout<<"These sides do not generate a triangle: ";
	    print();
    }
  }
  triangle(const triangle& d)
  {a=d.a; b=d.b; c=d.c; cout << "copy constructor" << endl;}
  void print(){cout<<"\t";a.print();cout<<",\t";b.print();cout<<",\t";c.print();cout<<endl;}
  void input(){
    //int k;
    do{
      //cout<<"Enter a: ";cin>>k;
      //a=k;
      a.input();
      //cout<<"Enter b: ";cin>>k;
      //b=k;
      b.input();
      //cout<<"Enter c: ";cin>>k;
      //c=k;
      c.input();
    }while(!check());
  }
};
void f2(){
	side a(3);
	side b = a;
	a.print();
	b.print();
}
int main(){f2();}
