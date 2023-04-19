#include <iostream>
#include <cmath>
using namespace std;
struct nodeCls{
  double data;
  nodeCls* next = nullptr;
};
int main(){
  nodeCls a, b;
  a.data = 1; b.data = 2;
  a.next = &b; 
  cout << a.data << endl;
  cout << b.data << endl;
  cout << (*(a.next)).data << endl;
  cout << (a.next) -> data << endl;
}