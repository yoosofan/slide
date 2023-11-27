#include<iostream>
using namespace std;
class Shape{
  string name = "shape";
  string color = "white";
public:
  Shape(string na, string co)
  {name=na; color = co;}
  int Area(void){return 0;}
  Shape() = default;
  friend ostream& operator <<(
      ostream& o1, const Shape& s1){
    o1 << "name: " << s1.name 
       << "\tcolor: " << s1.color;
    return o1;
  }
  string getColor(void){return color;}
};
class Square: public Shape{
  int d = 1;
public:
  int Area(void){return d*d;}
  Square(int d){this->d=d;}
  Square() = default;
  friend ostream& operator <<(
      ostream& o1, const Square& s1){
    o1<< Shape(s1)<<"\tside: "<<s1.d;
    return o1;
  }
};
int main(){
  Shape s;
  cout << s.Area() << endl;
  Square sq(3);
  cout << sq.Area() << endl;
  Shape* ps = &s;
  cout << ps->Area() << endl;
  ps = &sq;
  cout << ps->Area() <<endl;
  cout << ps->getColor() <<endl;
}
