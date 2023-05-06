#include<iostream>
using namespace std;
class Shape{
  string name = "shape";//char name[100]; '\0' رشته
  string color = "white";//strcpy, strcmp; char*color; str1=str2
 public:
  int Area(void){return 0;}
  Shape() = default;
  friend ostream& operator <<(ostream& o1, const Shape& s1){
    o1 << "name: " << s1.name << "\tcolor: " << s1.color;
    return o1;
  }
};
class Square: public Shape{
  int d = 1;
 public:
  int Area(void){return d*d;}
  Square(int d){this->d=d;}
  Square() = default;
  friend ostream& operator <<(ostream& o1, const Square& s1){
    o1 << Shape(s1) << "\tside: " << s1.d;
    return o1;
  }
};
int main(){
  Shape s;
  cout<< s.Area() << endl;
  Square sq(3);
  cout<< sq.Area() << endl;
  cout << sq << endl;
}
