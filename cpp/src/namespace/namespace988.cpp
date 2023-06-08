//Error
#include<iostream>
#include<fstream>
#include<cmath>
template<typename T> struct point{T x,y;};
namespace K1{
  struct student{ char name[20]; char stdno[20];};
  double pow(double x, double y){return std::pow(x,y);}
};
namespace A1{
struct student{ char*name; char* stdno; double avg;};
double pow(double x, double y){std::cout<<"my pow\n";return x*y;}
};
//using namespace A1;
class myClass {
	int a1;
	
  public: 
	static int count;
	void my(void);
};
void myClass::my(void){std::cout<<"my"<<std::endl;}
int myClass::count=3;

int main(){
  std::ofstream f1("input1.b",std::ios::binary);
  point<int> p1;
  point<double> p2;
  int aaa;
  double z=A1::pow(2,5);
  std::cout<<z<<std::endl;
  z=pow(2,5);
  std::cout<<z<<std::endl;
  A1::student st1;
  K1::student st3;
  z=K1::pow(2,5);
  std::cout<<z<<std::endl;
  int x;
  x=15;
  f1.write((char*)&x,sizeof(x));
  x++;
  f1.write((char*)&x,sizeof(x));
  x++;
  f1.write((char*)&x,sizeof(x));
  f1.close();
  std::cout<<myClass::count<<std::endl;
}
