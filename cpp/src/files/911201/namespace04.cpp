#include<iostream>
#include<fstream>
#include<cmath>
//using namespace std;
//struct point{int x,y;};
///////
//struct point{double x,y;};
template<typename T>
struct point{T x,y;};

namespace K1{
struct student{ char name[20]; char stdno[20];};
}
namespace A1{
struct student{ char*name; char* stdno; double avg;};
double pow(double x, double y){std::cout<<"my pow\n";return x*y;}
};
int main(){
  std::ofstream f1("input1.b",std::ios::binary);
  point<int> p1;
  point<double> p2;
  double z=A1::pow(2,5);
  std::cout<<z<<std::endl;
  z=pow(2,5);
  std::cout<<z<<std::endl;
  int x;
  x=16;
  f1.write((char*)&x,sizeof(x));
  x++;
  f1.write((char*)&x,sizeof(x));
  f1.close();
  return 0;
}/*
big indian
little indian
*/
