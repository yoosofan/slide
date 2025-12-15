#include<iostream>
#include "shape.h"
//#include "square.h"
using namespace std;
void f1(Shape* p){
  cout<<p->Area()<<endl;
  p->print();
}
int main(){Rectangle r1(4,5);
  Square sq(3);
  Circle c1(5);
  f1(&sq); f1(&c1); f1(&r1);
}