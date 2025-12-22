#include<iostream>
using namespace std;
class Shape{
protected:
  string name;
  string color;
public:
  int Area(){cout<<"in Shape"<<endl;return 0;}
  void show(){cout<<"show in shape"<<endl;}
};
class Square: public Shape{
  int d;
public:
  int Area()
  {cout<<"in Square"<<endl;return d*d;}
  Square(int d=1){this->d=d;}
};
class drive1 : public Square{
  public:
  void f(Shape a)
  {cout<<a.Area()<<endl;a.show();}
  drive1(int d=1):Square(d){}
};
void f1(Shape a)
{cout<<a.Area()<<endl;a.show();}
int main(){
  Shape s;  f1(s);
  Square sq(3); // f1(sq);
  drive1 d1; d1.f(sq);
  //cout<<sq.Area()<<endl;
  Shape* ps=&s; cout<<ps->Area()<<endl;
  //ps=&sq; cout<<ps->Area()<<endl;
}
