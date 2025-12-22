#include<iostream>
using namespace std;
class Shape{
  string name;
  string color;
public:
  virtual int Area(){return 0;}
  //Shape( string name="a", string color="White")
  Shape(string name, string color="White"){
    this->name=name;
    this->color=color;
    cout << "shape constructor" << endl;
  }
};
class Square: public Shape{
  int d;
public:
  void show(){
    cout<<"show in square Aread: " 
      << Area() << endl;
  }
  virtual int Area(){return d*d;}
  //Square(int d=1,string name="Square",string color="Black")//:Shape(name,color)
  Square(int d=1, string name="Square", 
    string color="Black"):Shape(name,color)  {
      cout << "square consructor" << endl;
      this->d=d;
    }
};
int main(){
  Shape s("sss");
  cout << s.Area() << endl;
  Square sq(3);
  cout << sq.Area() << endl;
  Shape* ps=&s;
  cout << ps->Area() << endl;
  ps = &sq;
  cout << ps->Area() << endl;
  Square*pq2 = &sq;
  cout << pq2->Area() << endl;
}
