#include<iostream>
using namespace std;
class Shape{protected:
  string name, color; public:
  Shape(string name="shape",
    string color="white"):
      name(name),color(color)
  {}
  virtual int Area() = 0; // abstrtact
};
class Square: public Shape{
  int d; public:
  virtual int Area(){
    return d*d;
  }
  Square(int d=1,
    string name="square",
    string color="blue"):
      Shape(name, color)
  {this->d=d;}
  void printAll(void){
    cout << "name: " <<
      this->name << '\t'
      << "color: " <<
      this->color << '\t' <<
      "d: " << this->d << endl;
  }
};
void f2(Shape p)
{cout<<p.Area()<<endl;}
void f1(Shape* p)
{cout<<p->Area()<<endl;}
int main(){
  Shape m1;
  Square sq(3);
  f2(sq); f1(&sq);
}