#include <iostream>
#include <cmath>
using namespace std;
struct point{
  double x=0, y=0;
  void input() {
    cout << "Enter X: ";
    cin >> x;
    cout << "Enter Y: ";
    cin >> y;
  }
  void print() {
    cout << '(' << x << ','
      << y << ')' << endl;
  }
  void move(double dx=1, double dy=0){
    x += dx;
    y += dy;
  }
  double magnitude(){ // length
    return sqrt(pow(x, 2)+pow(y, 2));
  }
};
int main(){
  point p1;
  p1.print();
  p1.input();
  p1.print();
  p1.move(3);
  cout << p1.magnitude() << endl;
}
