#include<iostream>
using namespace std;
template<typename Type> class array{
  static const int MAX = 200;
  Type a[MAX];
  int n;
  public:
  array(int n=20){this->n=n;}
  ~array(){n=0;}
  void input(void){}
  void print(void){}
};
int main(){
  array<int> m1, m2, m3;
  array<double> dm;
  array<char> cm;
  return 0;
}
