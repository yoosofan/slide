#include<iostream>
using namespace std;
class Shape{
  string name;
  string color;
public:
  virtual int Area(void){return 0;}
};
class Square: public Shape{
  int d;
public:
  virtual int Area(void){return d*d;}
  Square(int d=1){this->d=d;}
};
int main(){
  Shape s;
  cout<<__LINE__<<": "<<s.Area()<<endl;
  Square sq(3);
  cout<<__LINE__<<": "<<sq.Area()<<endl;
  Shape* ps=&s;
  cout<<__LINE__<<": "<<ps->Area()<<endl;
  ps=&sq;
  cout<<__LINE__<<": "<<ps->Area()<<endl;
  Square* pq2=&sq;
  cout<<__LINE__<<": "<<pq2->Area()<<endl;
  //pq2=&s;
}
