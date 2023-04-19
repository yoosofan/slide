#include <iostream>
#include <cmath>
using namespace std;
struct nodeCls{
  double data;
};
int main(){
  nodeCls a[10];
  for(int i = 0; i < 10; i++)
    a[i].data = double(i);
  for(int j = 0; j < 10; j++)
    cout << a[j].data << '\t';
  cout << endl;
}