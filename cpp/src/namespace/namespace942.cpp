#include<iostream>
#include<fstream>
#include<cmath>
//using namespace std;
template<typename T> struct point{T x,y;};
struct student{ char name[20]; char stdno[20];};
double pow(double x, double y){
  std::cout<<"my pow\n";
  return std::pow(x, y);
}
int main(){
  point<int> p1;
  point<double> p2;
  double z=pow(2,5);
  std::cout << z << std::endl;
  z = std::pow(2,5);
  std::cout << z << std::endl;
}