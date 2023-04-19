#include <iostream>
using namespace std;
struct point{
  double x, y;
  void input(void) {
    cout << "Enter the X value:" << endl;
    cin >> x;
    cout << "Enter the Y value:" << endl;
    cin >> y;
  }
  void print(void) {
    cout << "X value: " << x << endl;
    cout << "Y value: " << y << endl;
  }
  void move(double dx, double dy) {
    x += dx;
    y += dy;
  }
};
int main(){
  point p1;
  p1.input();
  p1.print();
}
