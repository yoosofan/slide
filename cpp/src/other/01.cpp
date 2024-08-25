#include<iostream>
int main(){
	int a = 0;
	int& b = a;
	int c = a;
	std::cout << a << "\t" << c << "\t" << std::endl;
	b = 3;
	std::cout << a << "\t" << b << '\t' << c << "\t" << std::endl;
  int *pa = nullptr;
  pa = & a;
  std:: cout << *pa << std::endl;
  pa = & c;
  c = 4;
  std:: cout << *pa << std::endl;
  b = c;
	std::cout << a << "\t" << c << "\t" << std::endl;
	return 0;
}
