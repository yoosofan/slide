#include<iostream>

void f1(int*);
void f3(int&);
int * f2();
int& f4();

int main(){
	int a = 0;
	int& b = a;
	int c = a;
	std::cout << __LINE__ << ":\t" << a << "\t" << c << "\t" << std::endl;
	b = 3;
	std::cout << __LINE__ << ":\t" << a << "\t" << b << '\t' << c << "\t" << std::endl;
  int *pa = nullptr;
  pa = & a;
  std:: cout << __LINE__ << ":\t" << *pa << std::endl;
  pa = & c;
  c = 4;
  std:: cout << __LINE__ << ":\t" << *pa << std::endl;
  b = c;
	std::cout << __LINE__ << ":\t" << a << "\t" << c << "\t" << std::endl;
  f1(pa);
  std::cout << __LINE__ << ":\t" << a << "\t" << c << "\t" << std::endl;
	pa = f2();
  std:: cout << __LINE__ << ":\t" << *pa << std::endl;
  f3(a);
  std::cout << __LINE__ << ":\t" << a << "\t" << c << "\t" << std::endl;
  std::cout << __LINE__ << ":\t" << f4() <<  std::endl;
  f4() = 21;
  std::cout << __LINE__ << ":\t" << f4() <<  std::endl;
  return 0;
}

void f1(int* pk){
  std::cout << __LINE__ << "\t pk: " << *pk << std::endl;
  *pk = 7;
  std::cout << __LINE__ << "\t pk: " << *pk << std::endl;
}

int* f2(){
  static int a = 5;
  return &a;
}

void f3(int& z){
  z = 9;
}

int& f4(){
  static int a = 17;
  return a;
}
