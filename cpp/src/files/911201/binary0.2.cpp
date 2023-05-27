#include<iostream>
#include<fstream>
using namespace std;
int main(){
  ifstream f1("input1.b",ios::binary);
  int x;
  f1.read((char*)&x,sizeof(int));
  cout<<x<<endl;
  f1.read((char*)&x,sizeof(int));
  cout<<x<<endl;
  return 0;
}