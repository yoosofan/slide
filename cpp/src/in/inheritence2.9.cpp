// Error
#include<iostream>
using namespace std;
class A{};
class Shape: public A{
protected:
  string name;
  string color;
public:
  int Area(){
    cout << "in Shape" << endl;
    return 0;
  }
  void show()
  {cout<<"show in shape"<<endl;}
};
class Square: protected Shape{
  int d;
public:
  int Area(){
    cout << "in Square" <<endl;
    return d*d;
  }
  Square(int d=1){this->d=d;}
};
class drive1 : public Square{
  public:
  drive1(int d=1):Square(d){}
  void f(Shape a){
    cout << a.Area() << endl;
    a.show();
  }
};
void f1(Shape a){
  cout << a.Area() << endl;
  a.show();
}
void f2(Square sq1){
  cout << sq1.Area() << endl;
}
int main(){
  Shape s;
  f1(s);
  Square sq(3); // f1(sq);
  drive1 d1;
  f2(sq);
  d1.f(sq);
  //cout<<sq.Area()<<endl;
  Shape* ps = &s;
  cout << ps->Area() << endl;
  //ps=&sq; cout<<ps->Area()<<endl;
}
