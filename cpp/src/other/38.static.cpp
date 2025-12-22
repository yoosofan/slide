/* 
 * Copyright 2016 Ahmad Yoosofan <yoosofan@myfastmail.com>, 
 * http://yoosofan.github.io/
 *
 * 2016/02/25
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
*/

#include <iostream>
#include <cmath>
using namespace std;
struct complexCls{
   static int count;
   static int numberCount(){return count;}
   double r,i;
   //explicit complexCls(double m=0 , double n=0) {r=m;i=n;}
   complexCls(double m=0 , double n=0) {r=m;i=n;count++;}
   ~complexCls() {count--;}
   //complexCls(int m=0 , int n=0) {r=m;i=n;}
   void Show(){cout<<'('<<r<<','<<i<<')'<<'\t'<<endl;}
   double Magnitude(){return sqrt(r*r+i*i);}
   //operator bool() const {cout<<"aaa:::: "<<endl;return r==0 && i==0 ? false : true;}
   bool operator!() const {cout<<"aaa:::: "<<endl;return !(r==0 && i==0 ? false : true);}
   complexCls operator++(){   // ++a
    cout<<"not int";    i++; r++;    return *this;  }
   complexCls operator++(int dummy){ // a++
    cout<<"int";    complexCls result=*this;    r++;    i++; return result;  }
}; 
complexCls operator +(const complexCls& a, const complexCls& b){
  complexCls result ;
  result.r = a.r + b.r;
  result.i = a.i + b.i;
  return result;
}
complexCls operator -(const complexCls& a,const complexCls& b){
  complexCls result ;
  result.r = a.r - b.r;
  result.i = a.i - b.i;
  return result;
}
complexCls operator *(const complexCls& a, const complexCls& b){
  complexCls result;
  result.r = a.r * b.r;
  result.i = a.i * b.i;
  return result;
}
int complexCls::count=0;
int main(){
      //complexCls a=2;//(2,3);
      complexCls a(2,3);
      complexCls b(4,5);
      complexCls c;
      if(!c) cout<< " c is zero "<<endl;
      else  cout<< " c is not zero "<<endl;
      c.Show();
      c=a+b; c.Show();
      c=a++; c.Show();
      c=++a; c.Show();
      //c = a+1;
      c = a + 12;
      cout<< "c.numberCount():\t"<<c.numberCount()<<endl;
      cout<< "complexCls::numberCount()"<<complexCls::numberCount()<<endl;
      
}
