#include <iostream>
using namespace std;
struct point {double x, y;};
point inputPoint(void) {
  point p1;
  cout << "Enter the X value:" << endl;
  cin >> p1.x;
  cout << "Enter the Y value:" << endl;
  cin >> p1.y;
  return p1;
}
void print(point p1) {
  cout << "X value: " << p1.x << endl;
  cout << "Y value: " << p1.y << endl;
}
point move(point p1, double dx, double dy) {
  p1.x += dx;
  p1.y += dy;
  return p1;
}
int main(){
  point p1 = inputPoint();
  print(p1);
}
