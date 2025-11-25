#pragma once
#include <iostream>
#include <cmath>
using namespace std;
#include "side.h"
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
