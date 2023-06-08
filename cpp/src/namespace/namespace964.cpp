#include<iostream>
#include<fstream>
#include<cmath>
template<typename T> struct point{T x,y;};
namespace K1{
  struct student{ char name[20]; char stdno[20];};
}
namespace A1{
  struct student{ char*name; char* stdno; double avg;};
  double myPow(double x, double y){std::cout<<"my pow\n";return std::pow(x, y);}
};
int main(){
  double z = A1::pow(2,5);
  z=myPow(2,5);
  std::cout<<z<<std::endl;
  int x;
  x=16;
  f1.write((char*)&x,sizeof(x));
  x++;
  f1.write((char*)&x,sizeof(x));
  f1.close();
}