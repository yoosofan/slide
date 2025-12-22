#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct stCls{
  int a;
  int b;
  char cs[200];
  void print(){
    cout<<"a : "<<a<<endl;
    cout<<"b : "<<b<<endl;
    cout<<"cs: "<<cs<<endl;
  }
};
int main(){
  ifstream f1("input1.b",ios::binary);
  stCls s1;
  f1.read((char*)&s1,sizeof(s1));
  s1.print();
  f1.read((char*)&s1,sizeof(s1));
  s1.print();
  f1.close();
  return 0;
}
  
  
