#include<iostream>
using namespace std;
class Shape{
  protected:
  string name;
  string color;
public:
  Shape(string name="shape", string color="white"):name(name),color(color){}
  virtual int Area(void) {return 0;}
};
class Square: public Shape{
  int d;
public:
  virtual int Area(void){return d*d;}
  Square(int d=1, string name="square",
    string color="blue"):Shape(name, color){this->d=d;}
  void printAll(void){
      cout<<"name: "<<this->name<<'\t'<<"color: "<<
      this->color<<'\t'<<"d: "<<this->d<<endl;
  }
};
int main(){
  Shape s;
  cout<<s.Area()<<endl;
  Square sq(3);
  cout << sq.Area() << endl;
  Shape* ps = &s;
  cout << ps->Area() << endl;
  ps = &sq;
  cout << ps -> Area() << endl;
  sq.printAll();
}
