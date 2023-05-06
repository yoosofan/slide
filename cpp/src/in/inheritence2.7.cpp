// Error
#include<iostream>
using namespace std;
class A{};
class Shape: public A{
protected:
  string name;
  string color;
public:
  int Area(void){
    cout << "in Shape" << endl;
    return 0;
  }
  void show(void)
  {cout<<"show in shape"<<endl;}
};
class Square: private Shape{
  int d;
public:
  int Area(void){
    cout << "in Square" << endl;
    return d*d;
  }
  Square(int d=1){this->d=d;}
};
void f1(Shape a){
  cout << a.Area() << endl;
  a.show();
}
int main(){
  Shape s;
  f1(s);
  Square sq(3);
  cout << sq.Area() << endl;
  // sq.show(); // Error
  Shape* ps = &s;
  cout << ps->Area() << endl;
  f1(sq);
  ps = &sq;
  cout<<ps->Area()<<endl;
}/*
in$ g++ inheritence2.7.cpp
inheritence2.7.cpp: In function ‘int main()’:
inheritence2.7.cpp:36:8: error: ‘Shape’ is an inaccessible base of ‘Square’
   36 |   f1(sq);
      |        ^
inheritence2.7.cpp:24:15: note:   initializing argument 1 of ‘void f1(Shape)’
   24 | void f1(Shape a){
      |         ~~~~~~^
inheritence2.7.cpp:37:9: error: ‘Shape’ is an inaccessible base of ‘Square’
   37 |   ps = &sq;
      |         ^~
*/
