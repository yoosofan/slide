#include<iostream>
using namespace std;
#include "myString.8.Functions.8.h"
#include "myString.8.h"
int main(){
  const char *st="salam"; 
  cout << myStringLength(st) << endl;
  myString s("Ali");
  //s.st[2]='c';
  myStringCopy(s,"Kamran");
}
