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
*/
#include <iostream>
#include <cmath>
using namespace std;
class complexCls{ double r,i;
 public:
  complexCls(int m=0,int n=0)
  {r=m;i=n;}
  void Show(void)
  {cout<<r<<"+ i "<<i<<endl;}
  double Magnitude(void)
  {return sqrt(r*r+i*i);}
  void input(void){
    cout<<"Enter real:"; cin>>r;
    cout<<"Enter imaginary:"; cin>>i;
  }
  complexCls add(complexCls b){
    complexCls c;
    c.r = r + b.r;
    c.i = this->i + b.i;
    return c;
  }
  friend complexCls add(complexCls a, complexCls b);
};
complexCls add(complexCls a, complexCls b){
  complexCls c=a;
  c.r += b.r;
  c.i += b.i;
  return c;
}
class side{
  unsigned d;
  public:
  side()=default;
  //~side()=default;
  //~side()=delete;
  side(int a){
    if(a<=0){cout<<"Side of a shape connot be negative or zero"<<endl;exit(0);}
    d=a;
  }
  side(const side&a){static int counter=0;counter+=1; this->d = a.d;cout<<counter<<"\tcopy constructor:"<<d<<endl;}
  void input(void){
    cout<<"Enter length of side:"; cin>>d;
    while(d<=0){
      cout<<"Side must be >0"<<endl;
      cout<<"Enter length of side:"; cin>>d;
    }
  }
  side operator+(side a){
    side b;
    //side b(*this); // b(a)
    b.d = this->d + a.d;
    this->show();cout<<" + "<<endl;
    return b;
  }
  bool operator>(side a){cout<<d<<" > "<<a.d<<endl; return d>a.d;}
  void show(void){cout<<d;}
};
class triangle{
  side a, b, c;
                       // (a.operator+(b)).operator>(c)
  bool check(void){return (a+b>c && a+c>b && b+c>a);}// true, false
  public:
  triangle(side a, side b, side c){
	  this->a=a; 
	  this->b=b;
	  this->c=c;
	  if(!check()){
		  cout<<"These sides do not generate a triangle: ";
		  show();
	  }
  }
  void show(void){cout<<"\t";a.show();cout<<",\t";b.show();cout<<",\t";c.show();cout<<endl;}
  void input(void){
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
void f2(void){
	side a(3);
	side b(4),c(5);
	side d;
	d = a + b;
	d.show();
	cout<<endl;
	d = a + -3;
	d.show();
	int k=3;
	side e(k);
	d = a + e;
	d.show();
	int i=1;
	double x =1;
	x = x + i;
	double y;
	y = i;
	y = (double)i;
	y = double(i);
	y = static_cast<double>(i);
	
	//triangle t(a,b,c);
	//t.show();
}
int f1(void){
  complexCls a(2,3),b(2,1),c(a);
  c=a.add(b);
  c.Show();
  c=add(a,b);
  c.Show();
  
}
int main(){
  //f1();
  f2();
  return 0;
}
