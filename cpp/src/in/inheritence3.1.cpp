#include<iostream>
using namespace std;
class Shape{
  protected:
  string name;
  string color;
public:
  Shape(string name="shape", 
      string color="white"):
        name(name), color(color){}
  int Area(){return 0;}
};
class Square: public Shape{
  int d;
public:
  int Area(){return d*d;}
  Square(int d1=1, string na="square", 
      string co="blue"):Shape(na, co)
  {d = d1;}
  void printAll(){
      cout<<"name: "<<this->name
          <<'\t'<<"color: "
          << this->color<<'\t'<<"d: "
          <<this->d<<endl;
  }
};
int main(){
  Shape s;
  cout << s.Area() << endl;
  Square sq(3);
  cout<<sq.Area()<<endl;
  Shape* ps=&s;
  cout<<ps->Area()<<endl;
  ps=&sq;
  cout<<ps->Area()<<endl;
  sq.printAll();
}
