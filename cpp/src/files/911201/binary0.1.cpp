#include<iostream>
#include<fstream>
//using namespace std;
int main(){
  std::ofstream f1("input1.b",std::ios::binary);
  int x;
  x=16;
  f1.write((char*)&x,sizeof(x));
  x++;
  f1.write((char*)&x,sizeof(x));
  f1.close();
}/*
big indian
little indian
*/
