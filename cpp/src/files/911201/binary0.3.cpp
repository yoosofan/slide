#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct stCls{
  int a;
  int b;
  char cs[200];
};
int main(){
  ofstream f1("input1.b",ios::binary);
  stCls s1;
  s1.a=12;
  s1.b=13;
  strcpy(s1.cs,"salam chetori ");
  f1.write((char*)&s1,sizeof(s1));
  s1.a=312;
  s1.b=413;
  strcpy(s1.cs,"salam khobam to chetori ");
  f1.write((char*)&s1,sizeof(s1));
  f1.close();
  return 0;
}
  
  
