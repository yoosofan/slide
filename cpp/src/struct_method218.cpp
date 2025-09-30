#include <iostream>
using namespace std;
struct point{
  double x, y;

  void input() {
    cout << "Enter the X value: ";
    cin >> x;
    cout << "Enter the Y value: ";
    cin >> y;
  }
  void print() {
    cout << "X value: "
      << x << endl;
    cout << "Y value: "
      << y << endl;
  }
  void move(double dx, double dy){
    x += dx;
    y += dy;
  }
};
int main(){
  point p1;
  p1.input();
  p1.print();
}
