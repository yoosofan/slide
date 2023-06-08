#include<iostream>
#include<fstream>
#include<cmath>
template<typename T>struct point{T x,y;};
namespace K1{
  struct student{ char name[20]; char stdno[20];};
}
namespace A1{
  struct student{ char*name; char* stdno; double avg;};
  double pow(double x, double y){
    std::cout<<"my pow\n";
    return std::pow(x,y);
  }
};
int main(){
  K1::student st1;
  A1::student st2;
  point<int> p1;
  point<double> p2;
  double z=pow(2,5);
  std::cout<<z<<std::endl;
  z=pow(2,5);
  std::cout<<z<<std::endl;
}